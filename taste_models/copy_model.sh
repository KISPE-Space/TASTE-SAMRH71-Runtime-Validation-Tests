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

 
echo "Done."
