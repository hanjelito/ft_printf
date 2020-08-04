/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 12:23:25 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_press_di(int space, int zero, t_printf *data, int nb)
{
	int flag;
	int nb_tmp;

	flag = -1;
	if (nb < 0 && (space > data->precision && data->zero_space == '0' ))
		write(1, "-", 1);
	else
		flag = 0;
	space = ft_pre_space_zero(space, data);
	if ((nb < 0 && nb > -2147483648) && flag == 0)
		ft_putchar_fd('-', 1);
	zero = ft_pre_zero(zero, data);
	if (nb < 0)
		nb_tmp = nb * (-1);
	else
		nb_tmp = nb;
	(data->dot == '.' && nb == 0 && data->precision == 0) ?
		0 : ft_putnbr_fd(nb_tmp, 1);
	ft_end_space(space, data);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}

void	print_di(t_printf *data, int nb)
{
	int len;
	int space;
	int	zero;

	data->len_str += len = ft_intlen(nb, 10);
	space = data->width;
	if (data->precision < len)
		space -= len;
	else
		space -= data->precision;
	if (nb < 0 && data->precision >= len)
		space -= 1;
	else if (data->dot == '.' && nb == 0 && data->precision == 0)
		space += 1;
	if (nb < 0)
		zero = (data->precision - len) + 1;
	else
		zero = data->precision - len;
	ft_press_di(space, zero, data, nb);
}
