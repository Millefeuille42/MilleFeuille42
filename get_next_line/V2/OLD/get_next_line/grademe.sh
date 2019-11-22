#!/bin/bash

i="1"

while [ $i -lt 1000 ]
do
	echo gcc -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
	gcc -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c test.c
	for fichier in "$@"
	do
		rm -f res.txt
		./a.out $fichier > res.txt
		RES=$(diff $fichier res.txt)
		if [ "$RES" = "" ]
		then
			echo $i : $fichier ok
			echo ""
			echo ""
		else
			echo $i : $fichier ERROR
			diff $fichier res.txt
			exit
		fi
	done
	((i++))
done
