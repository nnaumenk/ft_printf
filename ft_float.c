/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:15:42 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/20 15:15:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float_check(char *str, t_list *my)
{
	my->s = "1111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, my->s) == 0)
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("-inf", my));
		return (ft_my_strdup("-INF", my));
	}
	my->s = "0111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, my->s) == 0)
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("inf", my));
		return (ft_my_strdup("INF", my));
	}
	my->s = "0111111111111000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, my->s) == 0)
	{
		ft_strdel(&str);
		if (my->type_field >= 97)
			return (ft_my_strdup("nan", my));
		return (ft_my_strdup("NAN", my));
	}
	return (str);
}

int		ft_float_minus(long double *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}



char	*ft_float_add_minus(char *str, t_list *my)
{
	char *new;
	int i;

	new = ft_strnew(++my->len);
	new[0] = '-';
	i = 0;
	while (++i < my->len)
		new[i] = str[i - 1];
	ft_strdel(&str);
	return (new);
}

char	*ft_round_float_2(char *str, t_list *my)
{
	int		len;
	char	*new;

	len = my->len;
	new = ft_strnew(++my->len);
	while (len--)
		new[len + 1] = str[len];
	new[0] = '1';
	ft_strdel(&str);
	return (new);
}

char	*ft_round_float(char *str, t_list *my, char max_base)
{
	int		len;
	int		fl;
	char	*new;

	len = my->len;
	fl = 1;
	while (len-- && fl)
	{
		if (str[len] == '.')
			continue ;
		++str[len];
		if (str[len] == max_base + 1)
			str[len] = '0';
		else
			fl = 0;
	}
	if (fl)
		return (ft_round_float_2(str, my));
	return (str);
}

char 			*ft_float_binary(unsigned long *ptr)
{
	char *str;
	int len;

	len = 64;
	str = ft_strnew(len);
	while (len)
	{
		str[--len] = *ptr % 2 + '0';
		*ptr /= 2;
	}
	return (str);
}

int				ft_exponent(char *str)
{
	int i;
	int exponent;
	int two;

	i = -1;
	exponent = 0;
	two = 1024;
	while (++i < 11)
	{
		if (str[1 + i] == '1')
			exponent += two;
		two /= 2;
	}
	exponent -= 1023;
	return (exponent);
}

unsigned long ft_mantisa(char *str, int *exponent)
{
	int 			len;
	unsigned long 	mantisa;
	unsigned long 	two;

	len = 53;
	mantisa = 1;
	while (--len)
	{
		if (str[len + 11] == '1')
		{
			*exponent = *exponent - len;
			two = 1;
			mantisa = two;
			while (--len)
			{
				two *= 2;
				if (str[len + 11] == '1')
					mantisa += two;
			}
			mantisa += two * 2;
			break ;
		}
	}
	return (mantisa);
}

int			ft_float_dot(t_list *my)
{
	if (my->precision_field == -1)
		my->precision_field = 6;
	if (my->precision_field)
		return (1);
	return (0);
}

char		*ft_float_infinite_numbers(char *str, t_list *my)
{
	my->s = "0000000000000000000000000000000000000000000000000000000001000000";
	if (ft_strcmp(str, my->s) == 0)
		return (ft_my_strdup("0.0", my));
	my->s = "0000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, my->s) == 0)
		return (ft_my_strdup("0", my));
	my->s = "1000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, my->s) == 0)
		return (ft_my_strdup("0", my));
	return (str);
}

char		*ft_float(char *str_ptr, t_list *my)
{
	char			*str;
	unsigned long	mantisa;
	int				exponent;
	int				i;

	//printf("str = %s\n", str_ptr);
	str_ptr = ft_float_infinite_numbers(str_ptr, my);
	if (my->len)
		return (str_ptr);
	else
	{
		exponent = ft_exponent(str_ptr);
		mantisa = ft_mantisa(str_ptr, &exponent);
		str = ft_itoa_base_u("0123456789", &my->len, mantisa, 10);
		if (exponent > 0)
			while (exponent--)
				str = ft_str_mul_two(str, &my->len);
		else if (exponent < 0)
			while (exponent++)
				str = ft_str_div_two(str, &my->len);
	}
	return (str);
}

char		*ft_float_add_exponent(char *str, t_list *my, int count, char type)
{
	int 	len;
	int		i;
	char 	*new;

	if (count > 99 || count < -99)
		len = 3;
	else
		len = 2;
	new = ft_strnew(len + my->len + 2);
	i = -1;
	while (++i < my->len)
		new[i] = str[i];
	my->len += 2 + len;
	new[i++] = type;
	new[i++] = ft_minus(&count);
	while (len--)
	{
		new[i + len] = count % 10 + '0';
		count /= 10;
	}
	ft_strdel(&str);
	return (new);
}
