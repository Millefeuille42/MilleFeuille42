/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:18:26 by mlabouri          #+#    #+#             */
/*   Updated: 2020/02/04 15:42:53 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*mem;
	char	first;

	if (lst && *lst && del)
	{
		cur = *lst;
		first = 0;
		while (cur->next != NULL)
		{
			ft_lstdelone(cur, *del);
			if (!first)
			{
				mem = cur->next;
				*lst = NULL;
				cur->next = mem;
				first = 1;
			}
			else
				cur = cur->next;
		}
		ft_lstdelone(cur, *del);
	}
}
