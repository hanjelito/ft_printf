/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/06/29 13:22:48 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void		ft_pick2(int nb, t_printf *format)
{
    printf("%s\n", "ft_pick2");
	if (*format->str == '.')
	{
		format->dot = '.';
		format->str++;
		if (*format->str == '*')
		{
			format->precision = va_arg(format->argptr, int);
			if (format->precision == 0)
				format->precision = -1;
		}
		if (ft_isdigit(*format->str))
			format->precision = ft_atoi(format->str);
	}
    printf("%s\n", format->str);
}

void		ft_pick(int nb, t_printf *format)
{
    printf("%s\n", "ft_pick");
	if (*format->str == '-')
		format->tab = '-';
	if (*format->str == '0' && format->width == 0)
		format->zero_space = '0';
	if (*format->str == '*')
	{
		nb = va_arg(format->argptr, int);
		format->width = (nb < 0) ? (nb * -1) : nb;
		if (nb < 0)
			format->tab = '-';
	}
	if (ft_isdigit(*format->str) && *format->str != '0' &&
		format->width == 0 && format->dot != '.')
		format->width = ft_atoi(format->str);
	ft_pick2(nb, format);
}
void		ft_setformat(t_printf *format)
{
	int nb;
    printf("%s\n", "ft_setformat");

	format->width = 0;
	format->precision = 0;
	format->tab = ' ';
	format->zero_space = ' ';
	format->dot = ' ';
	while (!ft_isalpha(*format->str))
	{
		++format->str;
		ft_pick(nb, format);
		if (*format->str == '%')
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
