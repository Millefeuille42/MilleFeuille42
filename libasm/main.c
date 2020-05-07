/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:30:21 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/07 12:19:22 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

int main(void)
{
	printf("%zu", ft_strlen("lol"));
	printf("%zu", ft_strlen("lol"));
	printf("%zu", ft_strlen("lol"));

	return (0);
}

