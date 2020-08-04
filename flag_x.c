/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 10:01:31 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_fd(unsigned int number, char type)
{
	unsigned int	n;

	n = number;
	if (n > 16)
		ft_hexa_fd(n / 16, type);
	n = n % 16;
	if (n < 10)
		n += '0';
	else
		n += type == 'X' ? 55 : 87;
	ft_putchar_fd(n, 1);
}

void	ft_pres_x(int space, int zero, t_printf *data, int nb)
{
	space = ft_pre_space_zero(space, data);
	zero = ft_pre_zero(zero, data);
	(data->dot == '.' && nb == 0 && data->precision == 0)
		? 0 : ft_hexa_fd(nb, *data->str);
	ft_end_space(space, data);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}

void	print_x(t_printf *data, unsigned int nb)
{
	int len;
	int space;
	int	zero;

	data->type = *data->str;
	data->len_str += len = ft_intlen(nb, 16);
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space += (data->dot == '.' && nb == 0 && data->precision == 0) ? 1 : 0;
	zero = data->precision - len;
	ft_pres_x(space, zero, data, nb);
}
