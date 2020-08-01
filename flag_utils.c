/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/01 15:04:37 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void		ft_while(int space, int zero, t_printf *data, int nb)
{
	int flag;

	flag = -1;
	// printf("\n%d precision\n", data->precision);
	// printf("%d width\n", data->width);
	// printf("%d len_str\n", data->len_str);
	// printf("%d len\n", (int)ft_intlen(nb, 10));
	// printf("%c zero_space\n", data->zero_space);
	// printf("%c dot\n", data->dot);


	if (nb < 0 && (space > data->precision && data->zero_space == '0'))
	{
		write(1, "-", 1);
	}
	else
		flag = 0;
	
	// printf("\n%d nb", nb);
	// printf("\n%d flag\n", flag);
	
	while (space > 0 && data->tab != '-')
	{
		if (data->zero_space != '0' ||(data->dot == '.' && data->precision >= 0))
			data->len_str += write(1, " ", 1);
		else
			data->len_str += write(1, "0", 1);
		space--;
	}
	if (nb < 0 && flag == 0){
		ft_putchar_fd('-', 1);
	}
	while (zero-- > 0)
		data->len_str += write(1, "0", 1);
	(data->dot == '.' && nb == 0 && data->precision == 0)
		? 0 : ft_putnbr_fd(nb < 0  ? nb * (-1) : nb , 1);
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
	data->len_str -= (data->dot == '.' && nb == 0 &&
		data->precision == 0) ? 1 : 0;
}
