/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 21:24:55 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pre_space_zero(int space, t_printf *data)
{
	while (space > 0 && data->tab != '-')
	{
		if (data->zero_space != '0' ||(data->dot == '.' && data->precision >= 0))
			data->len_str += write(1, " ", 1);
		else
			data->len_str += write(1, "0", 1);
		space--;
	}
	return space;
}

int ft_pre_zero(int zero, t_printf *data)
{
	while (zero-- > 0)
		data->len_str += write(1, "0", 1);
	return zero;
}

int ft_end_space(int space, t_printf *data)
{
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
}
