/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:12:35 by mlabouri          #+#    #+#             */
/*   Updated: 2019/11/05 18:22:25 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (new && alst && *alst)
	{
		cur = *alst;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	if (!alst || !*alst)
		*alst = new;
}
