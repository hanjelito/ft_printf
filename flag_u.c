/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/28 18:21:21 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_espacios(int space, int zero, t_printf *format, unsigned int nb)
{
	int flag;

	flag = (nb < 0 && (space > format->precision && format->zero_space == '0'))
		? write(1, "-", 1) : 0;
	while (space > 0 && format->tab != '-')
	{
		format->len_str += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	while (zero-- > 0)
		format->len_str += write(1, "0", 1);
	(format->dot == '.' && nb == 0 && format->precision == 0)
		? 0 : ft_putnbr_fd(nb, 1);
	while (space-- > 0)
		format->len_str += write(1, " ", 1);
	format->len_str -= (format->dot == '.' && nb == 0 &&
		format->precision == 0) ? 1 : 0;
}

void		print_u(t_printf *format, unsigned int nb)
{
	int len;
	int space;
	int	zero;

	len = ft_intlen(nb, 10);
	format->len_str += len = ft_intlen(nb, 10);
	space = format->width - ((format->precision < len)
		? len : format->precision);
	space -= (nb < 0 && format->precision >= len) ? 1 : 0;
	space += (format->dot == '.' && nb == 0
		&& format->precision == 0) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	ft_espacios(space, zero, format, nb);
}