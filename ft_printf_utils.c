/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 23:19:06 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t		ft_intlen(long nb, int div)
{
	size_t count;

	count = 0;
	if (nb == 0)
	{
		count++;
		return (count);
	}
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / div;
		count++;
	}
	return (count);
}

int ft_isformat(t_printf *data)
{
	if (*data->str != 'd' && *data->str != 'i' &&
				*data->str != 'c' && *data->str != 's' &&
				*data->str != 'u' && *data->str != 'x' &&
				*data->str != 'X' && *data->str != 'p' &&
				*data->str != '%')
		return 1;
	return 0;
}

void ft_tab(int nb, t_printf *data)
{
		// printf("entro");
		data->tab = '-';
}

void ft_width(int nb, t_printf *data)
{
	if (nb < 0 && *data->str == '*')
		data->width = nb * -1;
	else if (*data->str == '*')
		data->width = nb;
	if(ft_isdigit(*data->str) && *data->str != '0' && data->width == 0 && data->dot != '.')
		data->width = ft_atoi(data->str);
}

void ft_precision(t_printf *data)
{
	data->dot = '.';
	data->str++;
	if (*data->str == '*')
		data->precision = va_arg(data->arg, int) == 0 ? -1 : data->precision;
	data->precision = ft_isdigit(*data->str) ? ft_atoi(data->str) : data->precision;
}

void ft_zero_space(t_printf *data)
{
	data->zero_space = '0';
}

void		ft_type_print(int nb, t_printf *data)
{
	if(*data->str == '-' )
		ft_tab(nb, data);
	if (*data->str == '*')
		nb = va_arg(data->arg, int);
	if (*data->str == '0' && data->width == 0)
		ft_zero_space(data);
	ft_width(nb, data);
	if (*data->str == '.')
		ft_precision(data);
}
