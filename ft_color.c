/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:11:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/12 15:11:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_color_check(char *color)
{
	if (ft_strcmp(color, "black") == 0)
		return (0);
	if (ft_strcmp(color, "red") == 0)
		return (0);
	if (ft_strcmp(color, "green") == 0)
		return (0);
	if (ft_strcmp(color, "yellow") == 0)
		return (0);
	if (ft_strcmp(color, "blue") == 0)
		return (0);
	if (ft_strcmp(color, "magenta") == 0)
		return (0);
	if (ft_strcmp(color, "cyan") == 0)
		return (0);
	if (ft_strcmp(color, "white") == 0)
		return (0);
	if (ft_strcmp(color, "eoc") == 0)
		return (0);
	return (1);
}

void	ft_color(t_list *my, char *color, int i)
{
	if (ft_strcmp(color, "black") == 0)
		my->str_full[i + 3] = '0';
	else if (ft_strcmp(color, "red") == 0)
		my->str_full[i + 3] = '1';
	else if (ft_strcmp(color, "green") == 0)
		my->str_full[i + 3] = '2';
	else if (ft_strcmp(color, "yellow") == 0)
		my->str_full[i + 3] = '3';
	else if (ft_strcmp(color, "blue") == 0)
		my->str_full[i + 3] = '4';
	else if (ft_strcmp(color, "magenta") == 0)
		my->str_full[i + 3] = '5';
	else if (ft_strcmp(color, "cyan") == 0)
		my->str_full[i + 3] = '6';
	else if (ft_strcmp(color, "white") == 0)
		my->str_full[i + 3] = '7';
	else
	{
		my->str_full[i + 2] = '0';
		my->str_full[i + 3] = '0';
	}
}

void	ft_add_color(t_list *my, int i, int color_len)
{
	char	*color;
	int		len;
	int		start;

	color = ft_strnew(color_len);
	len = -1;
	while (++len < color_len)
		color[len] = my->str_full[i - color_len + len];
	if (ft_color_check(color))
	{
		ft_strdel(&color);
		return ;
	}
	start = i - color_len - 1;
	my->str_full[start] = '\x1b';
	my->str_full[start + 1] = '[';
	my->str_full[start + 2] = '3';
	my->str_full[start + 4] = 'm';
	ft_color(my, color, start);
	ft_strdel(&color);
	start += 4;
	while (i < my->len_full)
		my->str_full[++start] = my->str_full[++i];
	my->len_full = start;
}


void	ft_color_search(t_list *my)
{
	int		i;
	int		color_len;

	i = -1;
	color_len = 0;
	while (++i < my->len_full)
	{
		if (my->str_full[i] == '{')
		{
			while (++i < my->len_full)
			{
				if (my->str_full[i] == '}')
				{
					if (color_len >= 3)
						ft_add_color(my, i, color_len);
					color_len = 0;
					break ;
				}
				++color_len;
			}
		}
	}
}
