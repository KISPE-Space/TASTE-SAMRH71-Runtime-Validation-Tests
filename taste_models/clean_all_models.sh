#!/bin/bash

for dir in model-* experimental-*; do
    [ -d "$dir" ] || continue

    echo -e "\nPruning $dir... \n"
    (
        cd "$dir" || exit 1
        ../prune_for_git.sh
    )
done
