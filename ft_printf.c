/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:03 by juan-gon          #+#    #+#             */
/*   Updated: 2020/06/29 13:18:52 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void		ft_formatletter(t_printf *format)
{
	format->len_str = 0;
	while (*format->str)
	{
		if (*format->str == '%')
		{
            printf("%s\n", "ft_formatletter");
			ft_setformat(format);
			// ft_advance(format);
			if (*format->str != 'd' && *format->str != 'i' &&
				*format->str != 'c' && *format->str != 's' &&
				*format->str != 'u' && *format->str != 'x' &&
				*format->str != 'X' && *format->str != 'p' &&
				*format->str != '%')
				break ;
		}
		else
			format->len_str += write(1, format->str, 1);
		format->str++;
	}
	va_end(format->argptr);
}

int			ft_printf(const char *s, ...)
{
	t_printf	format;
    printf("%s\n", "ft_printf");
	format.str = (char *)s;
	va_start(format.argptr, s);
	ft_formatletter(&format);
	va_end(format.argptr);
	return (format.len_str);
}

int main(void)
{
    ft_printf("%0-5");
}
