#!/usr/bin/bash

for src in "$@"
do
    if [[ ! $(nasm -f elf64 "$src") ]] ; then echo -e "$src\t[OK]" ; fi
done