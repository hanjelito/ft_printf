/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 13:21:57 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void			ft_putnbr_fd(long n, int fd)
{
	int long n2;

	n2 = (int long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	ft_putchar_fd(n2 % 10 + '0', fd);
}
