/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 23:16:46 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void		ft_press_u(int space, int zero, t_printf *data, unsigned int nb)
{
	int flag;

	flag = (nb < 0 && (space > data->precision && data->zero_space == '0'))
		? write(1, "-", 1) : 0;
	space  = ft_pre_space_zero(space, data);
	zero =  ft_pre_zero(zero, data);
	
	(data->dot == '.' && nb == 0 && data->precision == 0)
		? 0 : ft_putnbr_fd(nb, 1);
	ft_end_space(space, data);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}

void		print_u(t_printf *data, unsigned int nb)
{
	int len;
	int space;
	int	zero;

	len = ft_intlen(nb, 10);
	data->len_str += len = ft_intlen(nb, 10);
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space -= (nb < 0 && data->precision >= len) ? 1 : 0;
	space += (data->dot == '.' && nb == 0
		&& data->precision == 0) ? 1 : 0;
	zero = (nb < 0) ? (data->precision - len) + 1 : (data->precision - len);
	ft_press_u(space, zero, data, nb);
}