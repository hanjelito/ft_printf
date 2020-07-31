/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/31 13:29:56 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




void		print_di(t_printf *data, int nb)
{
	int len;
	int space;
	int	zero;

	printf("\n%d precision\n", data->precision);
	printf("%d width\n", data->width);
	printf("%d len_str\n", data->len_str);
	printf("%d len\n", (int)ft_intlen(nb, 10));
	printf("%c zero_space\n", data->zero_space);
	printf("%c dot\n", data->dot);
	printf("%c tab\n", data->tab);

	
	
	data->len_str += len = ft_intlen(nb, 10);
	space = data->width;
	if(data->precision < len)
		space -= len;
	else
		space -= data->precision;
	if (nb < 0 && data->precision >= len)
		space -= 1;
	else if(data->dot == '.' && nb == 0 && data->precision == 0)
		space += 1;
	if (nb < 0)
		zero =  (data->precision - len) + 1;
	else
		zero = data->precision - len;
	
	ft_while(space, zero, data, nb);
}
