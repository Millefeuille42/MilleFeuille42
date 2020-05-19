/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:30:21 by mlabouri          #+#    #+#             */
/*   Updated: 2020/05/19 15:22:12 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
char *ft_strcpy(char *dest, const char *src);
char *strcpy(char *dest, const char *src);

char *ft_strdup(const char *s);
char *strdup(const char *s);

int ft_strcmp(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2);

size_t ft_strlen(const char *s);
size_t strlen(const char *s);

ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);

ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);

int main(void)
{
	char *ft_dest;
	char *ft_src;
	char *dest;
	char *src;
	char buf[5];
	char ft_buf[5];
	int fd;
	ssize_t ft_size;
	ssize_t size;

	printf("%zu - %zu\n", ft_strlen("test"), strlen("test"));
	printf("%zu - %zu\n", ft_strlen(""), strlen(""));

	printf("%d - %d\n", ft_strcmp("ping", "test"), strcmp("ping", "test"));
	printf("%d - %d\n", ft_strcmp("test", "ping"), strcmp("test", "ping"));
	
	printf("%d - %d\n", ft_strcmp("teste", "tet"), strcmp("teste", "tet"));
	printf("%d - %d\n", ft_strcmp("tet", "teste"), strcmp("tet", "teste"));
	
	printf("%d - %d\n", ft_strcmp("tes", "test"), strcmp("tes", "test"));
	printf("%d - %d\n", ft_strcmp("test", "tes"), strcmp("test", "tes"));
	
	printf("%d - %d\n", ft_strcmp("", ""), strcmp("", ""));

	ft_dest = ft_strdup("test");
	dest = strdup("test");
	ft_src = ft_strdup("ping");
	src = strdup("ping");
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	ft_dest = ft_strcpy(ft_dest, ft_src);
	dest = strcpy(dest, src);
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	ft_dest = ft_strdup("test");
	dest = strdup("test");
	ft_src = ft_strdup("pin");
	src = strdup("pin");
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	ft_dest = ft_strcpy(ft_dest, ft_src);
	dest = strcpy(dest, src);
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	ft_dest = ft_strdup("");
	dest = strdup("");
	ft_src = ft_strdup("");
	src = strdup("");
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	ft_dest = ft_strcpy(ft_dest, ft_src);
	dest = strcpy(dest, src);
	printf("|%s| - |%s|\n", ft_dest, dest);
	printf("|%s| - |%s|\n", ft_src, src);

	size = write(1, "test", 4);
	write(1, "-" , 1);
	ft_size = ft_write(1, "test", 4);
	write(1, "\n", 1);
	printf("%zd - %zd\n", ft_size, size);

	fd = open("./test/test.txt", O_RDONLY);
	size = read(fd, buf, 4);
	fd = open("./test/test2.txt", O_RDONLY);
	ft_size = read(fd, ft_buf, 4);
	buf[4] = '\0';
	ft_buf[4] = '\0';
	printf("|%s| - |%s|\n", ft_buf, buf);
	printf("%zd - %zd\n", ft_size, size);

	printf("%zd - %zd\n", ft_read(-1, ft_buf, 1), read(-1, buf, 1));
	printf("%zd - %zd\n", ft_read(fd, ft_buf, -1), read(fd, buf, -1));	
	
	return (0);
}

