/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:26:12 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/19 17:26:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_strchardup(int len, char c)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	i = -1;
	while (++i < len)
		str[i] = c;
	return (str);
}

int		ft_strcount(char *str, int *spec)
{
	int			i;
	int			count;
	char const	*base = "0123456789abcdefABCDEF";

	count = 0;
	i = -1;
	while (str[++i])
		if (ft_strchr(base, str[i]))
			++count;
	if (spec[4] == '#' && count > 0)
		count--;
	return (count);
}

char 	*ft_my_strnew(int size)
{
	char *s;

	s = (char *)malloc(size + 1);
	s[size] = '\0';
	return (s);
}

char	*ft_my_strdup(const char *s, t_list *my)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	my->len = ft_strlen(s);
	str = ft_my_strnew(my->len);
	i = -1;
	while (++i < my->len)
		str[i] = s[i];
	return (str);
}

char	*ft_my_strdup_precision(const char *s, t_list *my)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	my->len = ft_strlen(s);
	if (my->precision_field != -1)
		if (my->len > my->precision_field)
			my->len = my->precision_field;
	str = ft_my_strnew(my->len);
	i = -1;
	while (++i < my->len)
		str[i] = s[i];
	return (str);
}

char	*ft_set_precision_long_min(t_list *my)
{
	char const	*max = "-9223372036854775808";
	char		*str;
	char		*new;
	int			len;
	int			i;

	if (my->precision_field <= 19)
		return (ft_my_strdup_precision(max, my));
	my->len = my->precision_field + 1;
	new = ft_strnew(my->len);
	i = 20;
	len = my->len;
	while (i-- > 1)
		new[--len] = max[i];
	while (len-- > 1)
		new[len] = '0';
	new[0] = '-';
	ft_strdel(&str);
	return (new);
}
