/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 12:53:36 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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
void *ft_calloc(size_t type, size_t numb)
{
	int i;
	void *p;

	i = type * numb;
	if (!(p = malloc(i)))
		return (NULL);
	while (i--)
		*(unsigned char*)p++ = 0;
	return (p - (type * numb));
}
void		ft_putchar(char x, int fd)
{
	write(fd, &x, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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

size_t	ft_strlen(const char *c)
{
	int count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}
