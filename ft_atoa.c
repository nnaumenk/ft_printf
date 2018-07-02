/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:34:38 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/18 12:38:11 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// char	*ft_float_a_prefix(char *str, t_list *my, int symbol, int sign)
// {
// 	char const		*base = "0123456789abcdef";
// 	char			*new;
// 	int				len;
// 	int				i;

// 	i = my->len;
// 	len = my->len + 3 + sign + my->dot;
// 	my->len = len;
// 	new = ft_strnew(len);
// 	while (i--)
// 		new[--len] = str[i];
// 	if (my->dot)
// 	 	new[--len] = '.';
// 	new[--len] = base[symbol];
// 	new[--len] = my->type_field + 23;
// 	new[--len] = '0';
// 	if (len)
// 		new[0] = '-';
// 	ft_strdel(&str);
// 	return (new);
// }

// char	*ft_atoa_to_hex_str(char *str, t_list *my, int symbol, int sign)
// {
// 	char	*buf;
// 	int		len;

// 	if (my->len)
// 		my->dot = 1;
// 	else
// 		my->dot = 0;
// 	str = ft_join_char(str, my->len, my->type_field + 15);
// 	len = my->len + 1;
// 	my->precision_field = -1;
// 	buf = ft_itoa_base_int("0123456789", my, my->buf, 10);
// 	if (buf[0] != '-')
// 	{
// 		str = ft_join_char(str, len, '+');
// 		++len;
// 	}
// 	str = ft_str_join_free(str, buf, len, my->len);
// 	my->len += len;
// 	str = ft_float_a_prefix(str, my, symbol, sign);
// 	return (str);
// }

// int		ft_atoa_to_hex_counter(long double num, int pr)
// {
// 	int count;
// 	int	mantisa;

// 	if (pr != -1)
// 		return (pr);
// 	count = 0;
// 	while (num)
// 	{
// 		++count;
// 		num *= 16.0;
// 		mantisa = (int)num;
// 		num -= mantisa;
// 	}
// 	return (count);
// }

// char	*ft_atoa_to_hex(long double num, t_list *my)
// {
// 	char		*base;
// 	char		*str;
// 	int			mantisa;
// 	int			i;

// 	if (my->type_field == 'A')
// 		base = "0123456789ABCDEF";
// 	else
// 		base = "0123456789abcdef";
// 	my->len = ft_atoa_to_hex_counter(num, my->precision_field);
// 	str = ft_strnew(my->len);
// 	i = -1;
// 	while (++i < my->len)
// 	{
// 		num *= 16.0;
// 		mantisa = (int)num;
// 		str[i] = base[mantisa];
// 		num -= mantisa; 
// 	}
// 	if ((num * 16.0) >= 7.0 && my->precision_field > 0)
// 		str = ft_round_str(str, my, base[15]);
// 	return (str);
// }

// int		ft_atoa_pow(long double *n, long double m)
// {
// 	int	pow;

// 	pow = 0;
// 	if (*n >= 1.0)
// 	{
// 		while (*n >= m)
// 		{
// 			++pow;
// 			*n /= 2.0;
// 		}
// 	}
// 	else
// 	{
// 		while (*n < m - 1)
// 		{
// 			*n *= 2.0;
// 			--pow;
// 		}
// 	}
// 	return (pow);
// }


// char	*ft_atoa(long double n, t_list *my)
// {
// 	char			*str_ptr;
// 	char			*str;
// 	int				symbol;
// 	int				sign;

// 	//str_ptr = ft_float_binary((unsigned long*)(&n));
// 	//str_ptr = ft_float_check(str_ptr, my);
// 	//if (my->len)
// 	//	return (str_ptr);
// 	//ft_strdel(&str_ptr);
// 	sign = ft_float_minus(&n);
// 	if (n == 0.0)
// 	{
// 		my->buf = 0;
// 		symbol = 0;
// 	}
// 	else if (my->flag_float == 'L')
// 		my->buf = ft_atoa_pow(&n, 16.0);
// 	else
// 		my->buf = ft_atoa_pow(&n, 2.0);
// 	symbol = (int)n;
// 	n -= symbol;
// 	str = ft_atoa_to_hex(n, my);
// 	str = ft_atoa_to_hex_str(str, my, symbol, sign);
// 	return (str);
//}
