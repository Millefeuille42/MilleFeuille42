#!/usr/bin/bash

for src in "$@"
do 
    if [[ ! $(nasm -f elf64 "$src") ]] ; then echo -e "$src\t\033[01;32m[OK]\033[00m" ; else  echo -e "$src\t\033[01;31m[KO]\033[00m" ; fi
done
