/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:34:20 by mlabouri          #+#    #+#             */
/*   Updated: 2020/09/29 11:34:20 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

char	file_exists(const char *file)
{
	struct stat	buffer;

	return ((char)(stat(file, &buffer) == 0));
}
