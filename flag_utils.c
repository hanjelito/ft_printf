/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/31 18:51:26 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void		ft_while(int space, int zero, t_printf *data, int nb)
{
	int flag;

	if (nb < 0 && (space > data->precision && data->zero_space == '0'))
	{
		write(1, "-", 1);
	}
	else
		flag = 0;
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
	
		? 0 : ft_putnbr_fd(nb < 0  ? nb * (1) : nb , 1);
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;

}
