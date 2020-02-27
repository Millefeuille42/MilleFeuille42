/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:33:35 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/27 17:26:59 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	int fd;
	struct s_cub conf;

	fd = open("./sample.cub", O_RDONLY);
	cub_parser(fd, &conf);
	close(fd);
}