/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:30:22 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:23 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int get_next_line_compact(char **line, int fd) {
	int l = 1, r, i;
	char c;
	char *tmp;

	if (!(*line = malloc(l)) || ((*line)[0] = '\0'))
		return (-1);
	while ((r = read(fd, &c, 1)) && l++ && c != '\n' && (i = -1)) {
		if (!(tmp = malloc(l)))
			return (-1);
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (r);
}

int get_next_line_opti(char **line, int fd) {
	int l = 1, r, i;
	char c;
	char *tmp;

	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((r = read(fd, &c, 1))) {
		l++;
		i = -1;
		if (!(tmp = malloc(l)) || (c == '\n' && (i = r)))
			return (i);
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (r);
}


// get_next_line_nul c de la merde
int get_next_line_nul(char **line, int fd) {
	int length = 1, ret, i;
	char c;
	char *tmp;

	pdt->machin;
	if (!(*line = malloc(length))) // Malloc line vide
		return (-1);
	(*line)[0] = '\0';
	while ((ret = read(fd, &c, 1)) && c != '\n') { // Lire jusque EOF ou /n
		if (!(tmp = malloc(++length))) // malloc length + 1 pour inclure le prochain char
			return (-1);
		i = 0;
		while (i < length - 2) { // copier line dans tmp moins l'espace supp
			tmp[i] = (*line)[i];
			i++;
		}
		tmp[i] = c; // ajouter le dernier char lu
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp; // mettre line a jour
	}
	return (ret); // retourner !0 si lecture 0 si EOF
}

__attribute__((destructor)) void ptdrTNul() {printf("Rip ta correction\n");}

int main(void) {
	char *line;
	int fd;

	//fd = open("./CMakeLists.txt", O_RDONLY);
	//while (get_next_line_opti(&line, fd) > 0)
	//	printf("-%s-\n", line);
	//printf("|||||-----|||||\n");
	//close(fd);
	//fd = open("./CMakeLists.txt", O_RDONLY);
	//while (get_next_line_compact(&line, fd) > 0)
	//	printf("-%s-\n", line);
	//printf("|||||-----|||||\n");
	//close(fd);
	fd = open("./CMakeLists.txt", O_RDONLY);
	while (get_next_line_nul(&line, fd) > 0)
		printf("-%s-\n", line);
	return 0;
}
