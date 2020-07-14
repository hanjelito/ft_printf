/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/14 13:23:55 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void		ft_while(int space, int zero, t_printf *format, int nb)
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
	(nb < 0 && flag == 0) ? ft_putchar_fd('-', 1) : 0;
	while (zero-- > 0)
		format->len_str += write(1, "0", 1);
	(format->dot == '.' && nb == 0 && format->precision == 0)
		? 0 : ft_putnbr_fd(nb, 1);
	while (space-- > 0)
		format->len_str += write(1, " ", 1);
	format->len_str -= (format->dot == '.' && nb == 0 &&
		format->precision == 0) ? 1 : 0;
}

void		ft_spacex(t_printf *format, int nb)
{
	int len;
	int space;
	int	zero;
    // printf("\n");
    // printf("<width>%d\n",format->width);
	// printf("<precision>%d\n",format->precision);
	// printf("<tab>%c\n",format->tab);
	// printf("<zero_space>%c\n",format->zero_space);
	// printf("<dot>%c\n",format->dot);
    
    // prinf(format->len_str);
	format->len_str += len = ft_intlen(nb, 10);
	space = format->width - ((format->precision < len)
		? len : format->precision);
	space -= (nb < 0 && format->precision >= len) ? 1 : 0;
	space += (format->dot == '.' && nb == 0 && format->precision == 0) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	ft_while(space, zero, format, nb);
}