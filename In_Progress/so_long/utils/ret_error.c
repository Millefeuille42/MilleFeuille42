/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:33:37 by mlabouri          #+#    #+#             */
/*   Updated: 2021/12/03 13:33:37 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Millefeuille on 22/06/2021.
//

#include "../so_long.h"

int	ret_error(char *msg, int err)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(msg, 2);
	return (err);
}
