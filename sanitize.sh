#!/bin/bash

if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    echo "Welcome in sanitize.sh help !"
    echo -e "\tThis script aims to ease sanitizer usage."
    echo -ne "\tIt configures it to make the binary continue after "
    echo "any non-critical error (all except segfaults for instance)."
    exit 0
fi

if [[ "$1" != "" ]]; then
    echo "Ignoring extra arguments." >&2
fi

export ASAN_OPTIONS=halt_on_error=0
make resanitize
./my_rpg
