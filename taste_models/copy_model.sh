#!/bin/bash

set -euo pipefail

# Ensure proper args
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_folder> <destination_folder>"
    exit 1
fi

SRC_DIR="$1"
DST_DIR="$2"

# Ensure source model exists
if [ ! -d "$SRC_DIR" ]; then
    echo "Error: Source folder '$SRC_DIR' does not exist."
    exit 1
fi

# Ensure dest model does not contain underscore characters
if [[ "$DST_DIR" == *"_"* ]]; then
    echo "Error: DST_DIR may not contain underscore characters: $DST_DIR" >&2
    exit 1
fi

# Ensure dest model does not exist
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
rm -rf "$DST_DIR/work/dataview"

echo "Removing nested .git folders"
find $DST_DIR -name .git | xargs rm -rf

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
if [[ ${#asn_files[@]} -eq 1 && ! -f "$DST_DIR/$DST_DIR.asn" ]]; then
    mv -f -- "${asn_files[0]}" "$DST_DIR/$DST_DIR.asn"
elif [[ ${#asn_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .asn files found in '$DST_DIR', not renaming" >&2
fi

acn_files=( "$DST_DIR"/*.acn )
if [[ ${#acn_files[@]} -eq 1 && ! -f "$DST_DIR/$DST_DIR.acn" ]]; then
    mv -f -- "${acn_files[0]}" "$DST_DIR/$DST_DIR.acn"
elif [[ ${#acn_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .acn files found in '$DST_DIR', not renaming" >&2
fi

# The QtCreater project file needs to exist, and have a good name
pro_files=( "$DST_DIR"/*.pro )
if [[ ${#pro_files[@]} -eq 1 && ! -f "$DST_DIR/$DST_DIR.pro" ]]; then
    mv -f -- "${pro_files[0]}" "$DST_DIR/$DST_DIR.pro"
elif [[ ${#pro_files[@]} -gt 1 ]]; then
    echo "WARNING: Multiple .pro files found in '$DST_DIR', not renaming" >&2
fi

# We can remove any pro.user* files. QtCreator creates these but they do not seem to prevent the project running correctly if not present
rm -f $DST_DIR/*.pro.user*

# Force the first line in the asn and acn files to ALL-UPPER-CASE model-name
sed -i "1s|.*|${DST_DIR^^}-DATAVIEW DEFINITIONS ::=|" $DST_DIR/$DST_DIR.asn
sed -i "1s|.*|${DST_DIR^^}-DATAVIEW DEFINITIONS ::= BEGIN|" $DST_DIR/$DST_DIR.acn

# Change ownership of all files and folders to taste:taste
sudo chown -R taste:taste $DST_DIR


echo ""
ls -l $DST_DIR
echo ""
echo "Done."
