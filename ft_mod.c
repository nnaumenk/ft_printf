/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:38:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:38:39 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_atoi(char **str)
{
	long		num;
	int			sign;
	int			i;

	i = 0;
	while (((*str)[i] >= 9 && (*str)[i] <= 13) || (*str)[i] == ' ')
		++i;
	sign = 1;
	if ((*str)[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if ((*str)[i] == '+')
		++i;
	num = 0;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		num = num * 10 + (((*str)[i++] - '0') % 10);
	*str = *str + i;
	return (sign * num);
}

long			ft_mod_int(t_list *my)
{
	long n;

	n = va_arg(my->ptr, long);
	if (my->len_field == -1)
		return ((int)(n));
	if (my->len_field == 0)
		return ((char)n);
	else if (my->len_field == 1)
		return ((short)n);
	return (n);
}

unsigned long	ft_mod_unint(t_list *my)
{
	unsigned long n;

	n = va_arg(my->ptr, unsigned long);
	if (my->len_field == -1)
		return ((unsigned int)(n));
	if (my->len_field == 0)
		return ((unsigned char)n);
	else if (my->len_field == 1)
		return ((unsigned short)n);
	return (n);
}

long double		ft_mod_float(t_list *my)
{
	if (my->flag_float == 'L')
		return (va_arg(my->ptr, long double));
	return (va_arg(my->ptr, double));
}
