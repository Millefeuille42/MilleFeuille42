/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:29:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/14 13:13:29 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*firstlst;
	t_list	*newlst;

	cur = l;
	newlst = malloc(sizeof(t_list *));
	if (!newlst || !l)
		return (NULL);
	firstlst = newlst;
	while (cur->next != NULL)
	{
		newlst->content = (*f)(cur->content);
		newlst->next = malloc(sizeof(t_list *));
		if (!newlst->next)
		{
			ft_lstclear(&firstlst, del);
			return (NULL);
		}
		newlst = newlst->next;
		cur = cur->next;
	}
	newlst->content = (*f)(cur->content);
	newlst->next = NULL;
	return (firstlst);
}
