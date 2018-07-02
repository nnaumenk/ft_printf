/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:47:59 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/18 19:48:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
		}
	}
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strnew(size_t size)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = '\0';
	while (size > 0)
		s[--size] = '\0';
	return (s);
}

char	*ft_chardup(const char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}

char	*ft_itoa_base_u(char const *str_base, int *len,
unsigned long n, int base)
{
	char			*str;
	int				i;

	*len = ft_numcount_base_unsign(n, base);
	str = ft_my_strnew(*len);
	i = *len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	return (str);
}

char *ft_strdup(char *str)
{
	char *new;
	int len;

	len = ft_strlen(str);
	new = ft_strnew(len);
	while (len--)
		new[len] = str[len];
	return (new);
}
