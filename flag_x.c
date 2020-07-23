/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/23 20:21:15 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		print_x(t_printf *data, char *str)
{
	int space;
	int len;
	int len_null;

	str = (str == NULL) ? "(null)" : str;
	len = ft_strlen(str);
	if (data->precision > 0 && 	data->precision < len)
		len -= (len - data->precision);
	else if (data->dot == '.' && data->precision == 0 && data->width == 0)
		len -= len;
	else if (data->precision == 0 && data->width > 0 && data->zero_space == ' ' && data->dot == '.')
		len -= len;
	if (data->width > 0)
		space = data->width - len;
	if (data->tab == '-')
		space += 1;
	if (data->tab == '-' && data->zero_space == '0')
		data->zero_space = ' ';
	else
		data->zero_space = data->zero_space;
	while (space-- > 0 && data->tab != '-')
		data->len_str += write(1, &data->zero_space, 1);
	if (str != NULL)
	{
		data->len_str += write(1, str, (data->dot == '.' && data->precision == -1) ? 0 : len);
	}
	while (space-- > 0 && data->tab == '-')
		data->len_str += write(1, &data->zero_space, 1);
}
