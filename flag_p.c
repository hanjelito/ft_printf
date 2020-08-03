/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:32:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 23:17:26 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		ft_press_p(int space, t_printf *data, int nb, char *ch)
{

	space = ft_pre_space_zero(space, data);
	write(1, "0x", 2);
	while (data->aux-- > 0)
		data->len_str += write(1, "0", 1);
	(data->dot == '.' && ch == NULL && data->precision == 0)
		? 0 : ft_memorypointer(ch);
	ft_end_space(space, data);
	data->len_str -= (data->dot == '.' && ch == NULL &&
		data->precision == 0) ? 1 : 0;
}

void		print_p(t_printf *data, char *ch)
{
	unsigned long	nb;
	int				space;
	int				len;

	len = ft_intlen((unsigned long)ch, 16) + 2;
	data->len_str += nb = ft_intlen((unsigned long)ch, 16) + 2;
	space = data->width - ((data->precision < len)
		? len : data->precision);
	space += (data->dot == '.' && nb == 0 && data->precision == 0) ? 1 : 0;
	space += (ch == NULL && data->dot == '.') ? 1 : 0;
	data->aux = data->precision - len + 2;
	ft_press_p(space, data, nb, ch);
}
