/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabouri <mlabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:27 by mlabouri          #+#    #+#             */
/*   Updated: 2019/12/12 17:04:21 by mlabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../trees/trees.h"

void ft_disp(char bin[], unsigned long long arg)
{
	void	(*func[4])(char, unsigned long long);

	func[0] = &disp_char;
	func[1] = &disp_string;
	func[bin[4]];
}