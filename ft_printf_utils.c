/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 20:27:31 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isformat(t_printf *data)
{
	if (*data->str != 'd' && *data->str != 'i' &&
				*data->str != 'c' && *data->str != 's' &&
				*data->str != 'u' && *data->str != 'x' &&
				*data->str != 'X' && *data->str != 'p' &&
				*data->str != '%')
		return (1);
	return (0);
}

int		ft_width1(int nb, t_printf *data)
{
	nb = va_arg(data->arg, int);
	if (nb < 0)
		data->width = nb * -1;
	else
		data->width = nb;
	if (nb < 0)
		data->tab = '-';
	return (nb);
}

void	ft_width2(int nb, t_printf *data)
{
	if (nb < 0 && *data->str == '*')
		data->width = nb * -1;
	else if (*data->str == '*')
		data->width = nb;
	if (ft_isdigit(*data->str) && *data->str != '0' &&
			data->width == 0 && data->dot != '.')
		data->width = ft_atoi(data->str);
}

void	ft_precision(t_printf *data)
{
	data->dot = '.';
	data->str++;
	if (*data->str == '*')
	{
		data->precision = va_arg(data->arg, int);
		if (data->precision == 0)
			data->precision = -1;
	}
	data->precision = ft_isdigit(*data->str) ?
		ft_atoi(data->str) : data->precision;
}

void	ft_type_print(int nb, t_printf *data)
{
	if (*data->str == '-')
		data->tab = '-';
	if (*data->str == '0' && data->width == 0)
		data->zero_space = '0';
	if (*data->str == '*')
		nb = ft_width1(nb, data);
	ft_width2(nb, data);
	if (*data->str == '.')
		ft_precision(data);
}
