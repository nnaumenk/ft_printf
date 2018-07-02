/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:15:50 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/28 21:15:51 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*ft_float_precision2(char *new, char *str, t_list *my, int af)
// {
// 	if (my->precision_field)
// 		new[my->i++] = '.';
// 	while (af-- > 1 && my->precision_field > 0)
// 	{
// 		--my->precision_field;
// 		new[my->i] = str[my->i];
// 		++my->i;
// 	}
// 	my->len = my->i;
// 	if (af >= 0)
// 		if (str[my->i] >= '5')
// 			new = ft_round_float(new, my, '9');
// 	my->i = my->len;
// 	while (my->precision_field-- > 0)
// 		new[my->i++] = '0';
// 	my->len = my->i;
// 	ft_strdel(&str);
// 	return (new);
// }

// char 	*ft_float_precision(char *str, t_list *my)
// {
// 	int 	after_dot_len;
// 	int		before_dot_len;
// 	char 	*new;

// 	if (my->precision_field == -1)
// 		my->precision_field = 6;
// 	my->i = -1;
// 	while (++my->i < my->len)
// 		if (str[my->i] == '.')
// 			break ;
// 	before_dot_len = my->i;
// 	after_dot_len = my->len - before_dot_len;
// 	new = ft_strnew(before_dot_len + my->precision_field + my->dot);
// 	my->i = -1;
// 	while (++my->i < before_dot_len)
// 		new[my->i] = str[my->i];
// 	new = ft_float_precision2(new, str, my, after_dot_len);
// 	return (new);
// }