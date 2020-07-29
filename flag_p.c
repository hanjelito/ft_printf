/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/29 10:56:10 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_lenhex_p(unsigned long nb)
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
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	ft_hexa(size_t number)
{
	size_t n;

	n = number;
	if (n >= 16)
		ft_hexa(n / 16);
	n = n % 16;
	n = n < 10 ? n + '0' : n + 87;
	ft_putchar_fd(n, 1);
}

void		ft_memorypointer(char *str)
{
	size_t	*x;

	x = (size_t *)&str;
	ft_hexa(*x);
}

void		ft_help(int space, t_printf *data, int nb, char *ch)
{
	int flag;

	while (space > 0 && data->tab != '-')
	{
		data->len_str += write(1, (data->zero_space != '0' ||
			(data->dot == '.' && data->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	write(1, "0x", 2);
	while (data->aux-- > 0)
		data->len_str += write(1, "0", 1);
	(data->dot == '.' && ch == NULL && data->precision == 0)
		? 0 : ft_memorypointer(ch);
	while (space-- > 0)
		data->len_str += write(1, " ", 1);
	data->len_str -= (data->dot == '.' && ch == NULL &&
		data->precision == 0) ? 1 : 0;
}

void		print_p(t_printf *data, char *ch)
{
	unsigned long	nb;
	int				space;
	int				len;

	len = ft_lenhex_p((unsigned long)ch) + 2;
	data->len_str += nb = ft_lenhex_p((unsigned long)ch) + 2;
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space += (data->dot == '.' && nb == 0 && data->precision == 0) ? 1 : 0;
	space += (ch == NULL && data->dot == '.') ? 1 : 0;
	data->aux = data->precision - len + 2;
	ft_help(space, data, nb, ch);
}
