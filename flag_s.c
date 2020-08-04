/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:28:31 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 10:41:46 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_printf *data, char *str)
{
	int space;
	int len;

	space = 0;
	str = (str == NULL) ? "(null)" : str;
	len = ft_strlen(str);
	if (data->precision > 0 && data->precision < len)
		len -= (len - data->precision);
	else if (data->dot == '.' && data->precision == 0 && data->width == 0)
		len -= len;
	else if (data->precision == 0 && data->width > 0
			&& data->zero_space == ' ' && data->dot == '.')
		len -= len;
	space = data->width > 0 ? data->width - len : space;
	space += data->tab == '-' ? 1 : 0;
	if (data->tab == '-' && data->zero_space == '0')
		data->zero_space = ' ';
	else
		data->zero_space = data->zero_space;
	while (space-- > 0 && data->tab != '-')
		data->len_str += write(1, &data->zero_space, 1);
	if (str != NULL)
		data->len_str += write(1, str, (data->dot == '.' &&
					data->precision == -1) ? 0 : len);
	ft_end_space(space, data);
}
