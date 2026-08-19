#!/bin/bash

for dir in taste_models/model-* taste_models/experimental-*; do
    [ -d "$dir" ] || continue

    echo -e "\nPruning $dir ... \n"
    (
        cd "$dir" || exit 1
        echo -e "Current folder: `pwd`"
        ../prune_for_git.sh
    )
done
