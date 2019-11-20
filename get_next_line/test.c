/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroberts <oroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:23:14 by oroberts          #+#    #+#             */
/*   Updated: 2019/11/14 13:13:29 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#include "get_next_line.h"

char	*strj(char const *s1, char const *s2)
{
	char	*res;
	int		size;

	size = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	if (!(res = malloc(size)))
		return (NULL);
	res[0] = '\0';
	strlcat(res, s1, size);
	strlcat(res, s2, size);
	return (res);
}


int main(int argc, char **argv)
{
	char **ligne;
	int i = -1;
	if (argc < 2)
	{
		printf("\n\n\n\n\n\t\t\tE R R O R   F I L E : %d\n\n\n\n\n", argc);
		return(2);
	}

	if (!(ligne = malloc(sizeof(char *))))
		return (3);
	if (!(*ligne = malloc(BUFFER_SIZE)))
		return (3);

	int fd = open(argv[1], O_RDONLY);

	char *tot = malloc(sizeof(char) * 1);
	tot[0] = 0;
	char *tmp;

	int count = 0;

	while ((i = get_next_line(fd, ligne)) == 1)
	{
		if (count != 0)
		{
			tmp = tot;
			tot = strj(tot, "\n");
			free (tmp);
		}
		count = 1;
		tmp = tot;
		tot = strj(tot, *ligne);
		free(tmp);
	}
	printf("%s", tot);

	//printf("fin");
	close(fd);

	free(tot);
	free(*ligne);
	free (ligne);


	if (i == -1)
		printf("\n\n\n\n\n\t\t\tE R R O R\n\n\n\n\n");
	return (0);

}
