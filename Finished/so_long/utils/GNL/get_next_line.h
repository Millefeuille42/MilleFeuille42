/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:34:07 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:07 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

size_t		ft_gstrlen(char *str);
char		*ft_gstrchr(const char *s, int c);
char		*ft_gsubstr(char *s, unsigned int start, size_t len);
char		*ft_gstrjoin(char *s1, char *s2);
int			get_next_line(int fd, char **line);

#endif
