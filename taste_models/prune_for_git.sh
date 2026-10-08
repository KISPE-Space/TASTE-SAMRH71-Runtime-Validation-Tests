#!/bin/bash

# Remove build folders
rm -rf work/build
rm -rf work/binaries
rm -rf work/Debug
rm -rf work/Dump
rm -f work/glue_*
rm -f work/skeletons_built

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

# Move all buried C source files into the higher level C folder
find work -path '*/implem/default/C/src/*' -type f | while read -r file; do

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

# Remove any C header files where the leafname matches the folder name
find work -path '*/C/src/*.h' -type f | while read -r file; do

    # File name without extension
    filename="$(basename "$file" .h)"

    # Top level folder containing the file
    parent_folder="$(dirname "$file" | cut -d'/' -f2)"
    if [ "$filename" = "$parent_folder" ]; then
        echo "Removing $file"
        rm -f "$file"
    fi
done

# Remove the implem/default/C/src and wrappers folders
find work -name 'implem' -type d | xargs rm -rf
find work -name 'wrappers' -type d | xargs rm -rf

# Also delete any nested Makefiles
find work -name 'Makefile' -type f | xargs rm -rf

# Remove some .pro files
rm -f work/taste.pro
find work -name "*.pro" | xargs rm -f

# Remove the dataview folder too
find work -name 'dataview' -type d | xargs rm -rf

# Also remove any nested .git folders. These are not required for our test framework - we use a simple git structure
find . -name '.git' | xargs rm -rf
find . -name '.gitignore' | xargs rm -f

# Change permissions on top level folder to 755
chmod 755 .

# Also ensure user and group is taste
sudo chown taste:taste .

# Finally, also perform a make clean
make clean

# Report what we did
echo -e "\nModel folder pruned for portability\n"
