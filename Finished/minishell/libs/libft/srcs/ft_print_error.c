/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:42:55 by dboyer            #+#    #+#             */
/*   Updated: 2020/10/27 18:43:33 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_len_arg(char id, t_sptf *sp)
{
	if (id == 's')
		return (ft_strlen(sp->a_s[++sp->s_i] = va_arg(sp->va, char *)));
	if (id == 'c')
		return ((sp->a_c[++sp->c_i] = (char)va_arg(sp->va, int)) * 0 + 1);
	return (ft_strlen(sp->a_i[++sp->i_i] = ft_itoa(va_arg(sp->va, int))));
}

static	int		get_len(const char *str, t_sptf *sptf)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1) && ft_cinset(*(str + 1), "scd") && str++)
			sptf->len += get_len_arg(*str, sptf);
		else
			sptf->len++;
		str++;
	}
	return (sptf->len);
}

static	int		cp_arg(const char *str, t_sptf *sptf)
{
	int		ret;
	char	*temp;

	if (*str == 's')
	{
		ret = ft_strlcat(sptf->ret, sptf->a_s[sptf->ctrs.s_i], sptf->len);
		sptf->ctrs.s_i += 1;
	}
	else if (*str == 'd')
	{
		ret = ft_strlcat(sptf->ret, sptf->a_i[sptf->ctrs.i_i], sptf->len);
		free(sptf->a_i[sptf->ctrs.i_i]);
		sptf->ctrs.i_i += 1;
	}
	else
	{
		if (!(temp = ft_calloc(sizeof(char), 2)))
			return (-85);
		*temp = sptf->a_c[sptf->ctrs.c_i];
		ret = ft_strlcat(sptf->ret, temp, sptf->len);
		free(temp);
		sptf->ctrs.c_i += 1;
	}
	return (ret);
}

static	void	get_ret(const char *str, t_sptf *sptf)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) && ft_cinset(*(str + 1), "scd") && str++)
		{
			sptf->ret[i] = 0;
			i = cp_arg(str, sptf);
		}
		else
			sptf->ret[i++] = *str;
		str++;
	}
}

void			ft_print_error(const char *str, ...)
{
	t_sptf		sptf;

	sptf.s_i = -1;
	sptf.i_i = -1;
	sptf.c_i = -1;
	sptf.ctrs.s_i = 0;
	sptf.ctrs.i_i = 0;
	sptf.ctrs.c_i = 0;
	sptf.len = 0;
	sptf.ret = 0;
	va_start(sptf.va, str);
	if (!(sptf.ret = ft_calloc(sizeof(char), get_len(str, &sptf) + 1)))
		return ;
	get_ret(str, &sptf);
	va_end(sptf.va);
	ft_putstr_fd(sptf.ret, STDERR_FILENO);
	free(sptf.ret);
}