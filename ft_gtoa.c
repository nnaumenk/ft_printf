/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/14 15:06:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char		*ft_gtoa_precision_2(char *str, t_list *my, int before_dot)
{
	char	*new;
	int		len;
	int		i;


	if (before_dot == -1)
		len = my->len;
	else if (str[0] == '0')
	{

		//while (s)
		len = my->precision_field + 2;
	}
	else if (before_dot == my->precision_field)
		len = my->precision_field;
	else
		len = my->precision_field + 1;
	new = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		++i;
	}
	//while (i < len

	my->len = len;
	if (str[i] >= '5')
		new = ft_round_float(new, my, '9');
	return(str);
}


char		*ft_gtoa_precision_exponent(char *str, t_list *my)
{
	char	*new;
	int		before_dot;
	int		i;

	before_dot = ft_char_index(str, '.');
	if (before_dot == -1)
		before_dot = my->len;
	my->len = my->precision_field + 1;
	new = ft_strnew(my->len);
	new[0] = str[0];
	new[1] = '.';
	i = 1;
	while (++i < my->len)
		new[i] = str[i - 1];
	if (str[i - 1] >= '5')
		new = ft_round_float(new, my, '9');
	new = ft_float_add_exponent(new, my, before_dot - 1, my->type_field - 2);
	return (new);
}

char		*ft_gtoa_precision(char *str, t_list *my)
{
	char	*new;
	int		before_dot;
	int		after_dot;
	int		i;

	i = -1;
	while (++i < my->len)
		if (str[i] == '.')
			break ;
	before_dot = i;
	after_dot = my->len - before_dot;
	my->dot = 0;
	if (after_dot)
		my->dot = 1;
	if (before_dot > my->precision_field && str[0] != '0')
		new = ft_gtoa_precision_exponent(str, my);
	else
		new = ft_gtoa_precision_2(str, my, before_dot);
	return (new);
}

char		*ft_gtoa(double n, t_list *my)
{
	char	*str_ptr;
	char	*str;
	int		counter_index;
	
	str_ptr = ft_float_binary((unsigned long*)(&n));
	str_ptr = ft_float_check(str_ptr, my);
	if (my->len)
		return (str_ptr);
	if (my->precision_field == -1)
		my->precision_field = 6;
	str = ft_float(str_ptr, my);
	str = ft_gtoa_precision(str, my);
	if (str_ptr[0] == '1')
		str = ft_float_add_minus(str, my);
	ft_strdel(&str_ptr);
	return (str);
}