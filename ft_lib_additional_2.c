/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_additional_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:41:20 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/22 10:41:25 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_chr_all(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] == c)
		++i;
	if (str[i])
		return (0);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
		if (s[index++] == (char)c)
			return ((char*)&s[index - 1]);
	if (s[index] == c)
		return ((char*)&s[index]);
	return (NULL);
}

int		ft_lenchr(const char *s, int *start, char c)
{
	int i;

	i = *start;
	while (s[*start])
		if (s[(*start)++] == c)
			return (*start - i - 1);
	return (*start - i);
}

int		ft_len_chr_str(const char *s, int start, char *sub)
{
	int i;
	int len;

	len = ft_strlen(sub);
	while (s[start])
	{
		i = len;
		while (i--)
			if (s[start] == sub[i])
				return (start);
		++start;
	}
	return (-1);
}

char	*ft_join_char(char *str_full, int len, char c)
{
	char	*new;

	new = ft_strnew(len + 1);
	new[len] = c;
	while (--len >= 0)
		new[len] = str_full[len];
	ft_strdel(&str_full);
	return (new);
}
