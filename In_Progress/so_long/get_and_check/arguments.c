/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:59 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#include "../so_long.h"

inline static int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ret_error("No such file or directory", 0);
	return (fd);
}

inline static int	check_ext(char *path)
{
	int					len;
	int					i;
	const static char	ext[4] = ".ber";

	len = (int)ft_strlen(path);
	i = len - 4;
	while (i < len && path[i] && ext[i - (len - 4)])
	{
		if (path[i] != ext[i - (len - 4)])
			return (ret_error("Invalid extension\n", 1));
		i++;
	}
	return (0);
}

int	get_and_check_arguments(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ret_error("Invalid numbers of arguments\n", -1));
	if (check_ext(argv[1]))
		return (-1);
	fd = check_path(argv[1]);
	return (fd);
}
