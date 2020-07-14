/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/13 14:46:21 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
// verifica si es un formato
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

void		ft_type_print(int nb, t_printf *data)
{
	// printf("\n<>%0*17<>\n",va_arg(data->arg, int));
	data->tab = *data->str == '-' ? '-' : data->tab;
	data->zero_space = *data->str == '0' && data->width == 0 ? '0' : data->zero_space;
	if (*data->str == '*')
	{
		nb = va_arg(data->arg, int);
		data->width = (nb < 0) ? (nb * -1) : nb;
		data->tab = nb < 0 ? '-' : data->tab;
	}
	if (ft_isdigit(*data->str) && *data->str != '0' && data->width == 0 && data->dot != '.')
		data->width = ft_atoi(data->str);
	if (*data->str == '.')
	{
		data->dot = '.';
		data->str++;
		if (*data->str == '*')
		{
			data->precision = va_arg(data->arg, int);
			data->precision = data->precision == 0 ? -1 : data->precision;
		}
		data->precision = ft_isdigit(*data->str) ? ft_atoi(data->str) : data->precision;
	}
}
// libft
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

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n2;

	n2 = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	ft_putchar_fd(n2 % 10 + '0', fd);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

