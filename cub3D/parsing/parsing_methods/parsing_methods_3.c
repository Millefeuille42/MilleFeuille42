/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_methods_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:06:41 by mlabouri          #+#    #+#             */
/*   Updated: 2020/04/10 15:23:43 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

inline static int	safe_join(char **s1, char **s2)
{
	char *temp;
	char *temp2;

	if (!(temp = ft_strjoin(*s1, *s2)))
		return (-3);
	temp2 = ft_strjoin(temp, ",");
	free(temp);
	if (temp2 == NULL)
		return (-3);
	free(*s1);
	*s1 = ft_strdup(temp2);
	free(temp2);
	if (*s1 == NULL)
		return (-3);
	return (0);
}

int					map_p(struct s_conf *conf, int fd)
{
	int		err;
	char	*line;
	char	*final;

	final = NULL;
	while ((err = get_next_line(fd, &line)))
	{
		if (err == -1 || (err = safe_join(&final, &line)))
			break ;
		free(line);
	}
	if (!(err))
		err = safe_join(&final, &line);
	free(line);
	if (!(conf->map = ft_split(final, ',')))
		err = -3;
	free(final);
	if (err)
		return (-3);
	return (0);
}
