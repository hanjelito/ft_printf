/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/07 13:22:22 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
// verifica si es un formato
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

void		ft_pick2(int nb, t_printf *data)
{
	if (*data->str == '.')
	{
		data->dot = '.';
		data->str++;

		if (*data->str == '*')
		{
			data->precision = va_arg(data->argptr, int);
			if (data->precision == 0)
				data->precision = -1;
		}
		if (ft_isdigit(*data->str))
			data->precision = ft_atoi(data->str);
	}
}

void		ft_pick(int nb, t_printf *data)
{
	if (*data->str == '-')
		data->tab = '-';
	else if (*data->str == '0' && data->width == 0)
		data->zero_space = '0';
	else if (*data->str == '*')
	{
		nb = va_arg(data->argptr, int);
		data->width = (nb < 0) ? (nb * -1) : nb;
		if (nb < 0)
			data->tab = '-';
	}
	else if (ft_isdigit(*data->str) && *data->str != '0' &&
		data->width == 0 && data->dot != '.')
		data->width = ft_atoi(data->str);
	ft_pick2(nb, data);
}
void		ft_setformat(t_printf *data)
{
	int nb;	
	data->width 		= 0;
	data->precision 	= 0;
	//optimizar
	data->tab 			= ' ';
	data->zero_space 	= ' ';
	data->dot 			= ' ';

	// data->len_str		= 5;
	//optimizar
	while (!ft_isalpha(*data->str))
	{
		++data->str;
		ft_pick(nb, data);
		if (*data->str == '%')
			break ;
	}
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
int	ft_atoi(const char *str)
{
	int		neg;
	int		i;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
