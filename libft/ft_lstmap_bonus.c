/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:29:10 by mlabouri          #+#    #+#             */
/*   Updated: 2019/10/12 17:06:09 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*cur;
	t_list	*firstlst;
	t_list	*newlst;

	cur = lst;
	newlst = malloc(sizeof(t_list *));
	firstlst = newlst;
	while (cur->next != NULL)
	{
		newlst->content = (*f)(cur->content);
		newlst->next = malloc(sizeof(t_list *));
		newlst = newlst->next;
		cur = cur->next;
	}
	newlst->content = (*f)(cur->content);
	newlst->next = NULL;
	return (firstlst);
}
