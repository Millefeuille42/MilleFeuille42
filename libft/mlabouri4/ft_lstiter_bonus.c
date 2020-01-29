/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:26:16 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/05 18:53:56 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	if (lst && f)
	{
		cur = lst;
		while (cur->next != NULL)
		{
			(*f)(cur->content);
			cur = cur->next;
		}
		(*f)(cur->content);
	}
}
