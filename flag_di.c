/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/21 12:46:33 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void		ft_while(int space, int zero, t_printf *data, int nb)
{
	int flag;

	flag = (nb < 0 && (space > data->precision && data->zero_space == '0'))
		? write(1, "-", 1) : 0;
	while (space > 0 && data->tab != '-')
	{
		data->len_str += write(1, (data->zero_space != '0' ||
			(data->dot == '.' && data->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	(nb < 0 && flag == 0) ? ft_putchar_fd('-', 1) : 0;
	while (zero-- > 0)
		data->len_str += write(1, "0", 1);
	(data->dot == '.' && nb == 0 && data->precision == 0)
		? 0 : ft_putnbr_fd(nb, 1);
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}

void		ft_spacex(t_printf *data, int nb)
{
	int len;
	int space;
	int	zero;

	data->len_str += len = ft_intlen(nb, 10);
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space -= (nb < 0 && data->precision >= len) ? 1 : 0;
	space += (data->dot == '.' && nb == 0 && data->precision == 0) ? 1 : 0;
	zero = (nb < 0) ? (data->precision - len) + 1 : (data->precision - len);
	ft_while(space, zero, data, nb);
}