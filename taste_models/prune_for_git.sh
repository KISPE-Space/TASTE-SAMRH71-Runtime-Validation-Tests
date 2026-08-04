#!/bin/bash

# Remove build folders
rm -rf work/build
rm -rf work/binaries
rm -rf work/Debug
rm -rf work/Dump
rm -rf work/glue_*

# QT Creator user files
#find . -name "*.pro.user*" | xargs rm -f
find . -name ".qtc_clangd" | xargs rm -rf

# Aadl files
find . -name "*.aadl" | xargs rm -f

# msc files
find . -name "*.msc" | xargs rm -f

# make.info file
rm -f make.info

# Interfaces info file
rm -f interfaces_info.h

# Remove all symlinks
find . -name 'C' -type l | xargs rm -f

# Move all buried C files into the higher level C folder
find . -path './*/implem/default/C/src/*.c' -type f | while read -r file; do

    # Remove the fixed suffix to get the match_folder
    match_folder="${file%/implem/default/C/src/*}"

    # File name only
    filename="$(basename "$file")"

    # Destination directory
    dest_dir="$match_folder/C/src"
    mkdir -p "$dest_dir"

    echo "Moving $file -> $dest_dir/$filename"
    mv "$file" "$dest_dir/$filename"
done

# Remove the implem/default/C/src andd wrappers folders
find work -name 'implem' -type d | xargs rm -rf
find work -name 'wrappers' -type d | xargs rm -rf

# Also delete any nested Makefiles
find work -name 'Makefile' -type f | xargs rm -rf

# Remove some .pro files
rm -f work/taste.pro
find work -name "*.pro" | xargs rm -f
find work -name "*.h" | xargs rm -f

# Remove the dataview folder too
find work -name 'dataview' -type d | xargs rm -rf

# Also remove any nested .git folders. These are not required for our test framework - we use a simple git structure
find . -name '.git' | xargs rm -rf

# Change permissions on top level folder to 755
chmod 755 .

# Also ensure user and group is taste
sudo chown taste:taste .
