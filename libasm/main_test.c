
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define LEN(x) if (ft_strlen(x) != strlen(x)) break;
#define CPY(x, y, y2, y3) if ((ft_strcpy(y, x) != strcpy(y, x)) || (ft_strcpy(y2, x) != strcpy(y2, x)) || (ft_strcpy(y3, x) != strcpy(y3, x)))  break;
#define WRT(x) ft_write(1, &x, 1);

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

char **random_string(int size, char **str)
{
	*str = malloc(sizeof(char) * size + 1);
	for (int i = 0; i <= size; i++)
		(*str)[i] = (char)((random() % 78) + 30);
	return (str);
}

int main(void)
{
	char **sstr;
	char **dstr;

	srandom(time(NULL));
	sstr = malloc(sizeof(char *));
	dstr = malloc(sizeof(char *) * 3);

	for (int i = 0; i < 1000000; i++)
	{
		sstr = random_string(50, sstr);
		dstr[0] = malloc(sizeof(char) * 51);
		dstr[1] = malloc(sizeof(char) * 61);
		dstr[2] = malloc(sizeof(char) * 31);

		LEN(*sstr)
		CPY(*sstr, dstr[0], dstr[1], dstr[2])
		WRT((*sstr)[i])

		printf("lol");

		free(*sstr);
		free(dstr[0]);
		free(dstr[1]);
		free(dstr[2]);
	}

	free(sstr);
	free(dstr);
	return (0);
}