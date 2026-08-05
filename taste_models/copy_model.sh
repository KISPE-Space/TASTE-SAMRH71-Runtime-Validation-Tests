#!/bin/bash

set -euo pipefail

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_folder> <destination_folder>"
    exit 1
fi

SRC_DIR="$1"
DST_DIR="$2"

if [ ! -d "$SRC_DIR" ]; then
    echo "Error: Source folder '$SRC_DIR' does not exist."
    exit 1
fi

if [ -e "$DST_DIR" ]; then
    echo "Error: Destination '$DST_DIR' already exists."
    exit 1
fi

echo "Copying '$SRC_DIR' -> '$DST_DIR'..."
cp -a "$SRC_DIR" "$DST_DIR"

echo "Removing auto-generated build folders and files from $DST_DIR ..."
rm -rf "$DST_DIR/work/binaries" 
rm -rf "$DST_DIR/work/build"
rm -rf "$DST_DIR/work/Debug"
rm -rf "$DST_DIR/work/Dump" 
rm -f "$DST_DIR/work/glue_*"


echo "Renaming top-level files containing '$SRC_DIR'..."

find "$DST_DIR" -maxdepth 1 -type f | while read -r file; do
    filename=$(basename "$file")

    if [[ "$filename" == *"$SRC_DIR"* ]]; then
        new_filename="${filename//$SRC_DIR/$DST_DIR}"

        echo "  $filename -> $new_filename"
        mv "$file" "$DST_DIR/$new_filename"
    fi
done

echo "Replacing '$SRC_DIR' with '$DST_DIR' in file contents..."
grep -rl --binary-files=without-match -- "$SRC_DIR" "$DST_DIR" | while read -r file; do
	sed -i "s/${SRC_DIR}/${DST_DIR}/g" "$file"
	echo "Updated file $file"
done

echo "Checking for legacy name in asn, acn, files etc..."
shopt -s nullglob

asn_files=( "$DST_DIR"/*.asn )
if [[ ${#asn_files[@]} -eq 1 ]]; then
    mv -- "${asn_files[0]}" "$DST_DIR/$DST_DIR.asn"
elif [[ ${#asn_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .asn files found in '$DST_DIR', not renaming" >&2
fi

acn_files=( "$DST_DIR"/*.acn )
if [[ ${#acn_files[@]} -eq 1 ]]; then
    mv -- "${acn_files[0]}" "$DST_DIR/$DST_DIR.acn"
elif [[ ${#acn_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .acn files found in '$DST_DIR', not renaming" >&2
fi

# The QtCreater project file needs to exist, and have a good name
pro_files=( "$DST_DIR"/*.pro )
if [[ ${#pro_files[@]} -eq 1 ]]; then
    mv -- "${pro_files[0]}" "$DST_DIR/$DST_DIR.pro"
elif [[ ${#pro_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .pro files found in '$DST_DIR', not renaming" >&2
fi

# We can remove any pro.user* files. QtCreator creates these but they do not seem to prevent the project running correctly if not present
rm -rf "$DST_DIR/*.pro.user*"

# Change ownership of all files and folders to taste:taste
sudo chown -R taste:taste $DST_DIR


echo ""
ls -l $DST_DIR
echo ""
echo "Done."
