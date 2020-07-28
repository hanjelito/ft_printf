/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/28 18:14:41 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexamayus(unsigned int number, char type)
{
	unsigned int	n;

	n = number;
	if (n > 16)
		ft_hexamayus(n / 16, type);
	n = n % 16;
	n = n < 10 ? n + '0' : n + (type == 'X' ? 55 : 87);
	ft_putchar_fd(n, 1);
}

void		ft_auxiliar(int space, int zero, t_printf *data, int nb, char type)
{
	int flag;

	while (space > 0 && data->tab != '-')
	{
		data->len_str += write(1, (data->zero_space != '0' ||
			(data->dot == '.' && data->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	while (zero-- > 0)
		data->len_str += write(1, "0", 1);
	(data->dot == '.' && nb == 0 && data->precision == 0)
		? 0 : ft_hexamayus(nb, type);
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}

void		print_x(t_printf *data, unsigned int nb, char type)
{
	int len;
	int space;
	int	zero;

	data->len_str += len = ft_intlen(nb, 16);
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space += (data->dot == '.' && nb == 0 && data->precision == 0) ? 1 : 0;
	zero = data->precision - len;
	ft_auxiliar(space, zero, data, nb, type);
}