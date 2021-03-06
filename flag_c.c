/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 10:07:17 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_printf *data, int nb)
{
	int space;
	int zero;

	zero = 0;
	if (data->zero_space == '0' && data->width > 0)
		zero = data->width - 1;
	space = (data->width > 0) ? (data->width) : 0;
	space -= (data->width > 0 && data->tab != '-') ? 1 : 0;
	while (zero-- > 0 && data->tab != '-')
	{
		data->len_str += write(1, "0", 1);
		space = 0;
	}
	while (space-- > 0 && data->tab != '-')
		data->len_str += write(1, " ", 1);
	data->len_str += write(1, &nb, 1);
	while (space-- > 0 && data->tab == '-')
		data->len_str += write(1, " ", 1);
}
