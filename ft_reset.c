/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:43:05 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/21 11:43:06 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_flags(t_list *my)
{
	my->flag_comma = 0;
	my->flag_minus = 0;
	my->flag_plus = 0;
	my->flag_space = 0;
	my->flag_hash = 0;
	my->flag_zero = 0;
	my->width_field = -1;
	my->precision_field = -1;
	my->len_field = -1;
	my->type_field = 0;
	my->argptr_counter = -1;
	my->unicode_check = 0;
	my->len = 0;
}
