/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:19:00 by dboyer            #+#    #+#             */
/*   Updated: 2020/05/12 22:03:48 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/includes/string_object.h"
#include <stdio.h>

int main(void)
{
	char	*nom = "mlabouri";
	char	*prenom = "millefeuille";

	t_string string = ft_string("ceci est un test");
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.push(&string, " ok!");
	string.upper(&string);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.lower(&string);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.clear(&string);

	string = ft_string("#{nom}, je suis #{nom}, on m'appelle #{nom}");
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.replace(&string, "#{nom}", nom, 3);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.replace(&string, nom, prenom, 2);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.delete(&string, nom, 2);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.delete(&string, prenom, -1);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.delete(&string, "e", -1);
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.prepend(&string, "j'aime le chocolat");
	printf("size = %zu -- content = %s\n",string.size, string.content);
	string.clear(&string);
	return (0);
}
