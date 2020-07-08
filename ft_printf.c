/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:03 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/08 11:00:38 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void		ft_formatletter(t_printf *data)
{
	data->len_str = 0;
	while (*data->str)
	{
		if (*data->str == '%')
		{
			ft_setformat(data);
			// ft_advance(data);
			if(ft_isformat(data) == 1)
				break ;
		}
		else
			data->len_str += write(1, data->str, 1);
		data->str++;
	}
	va_end(data->arg);
}

int			ft_printf(const char *format, ...)
{
	t_printf	data;
	data.str = (char *)format;
	va_start(data.arg, format);
	ft_formatletter(&data);
	va_end(data.arg);
	return (data.len_str);
}

int main(void)
{

	// printf("\n|%d|\n",	  printf("%08d", 3));
	// printf("\n|%d|\n", ft_printf("%08d", 3));
	// printf("%0*s", "s");

	int num = -12; 
	// int num2 = 12345; 
	// printf("%d\n",num2); 
	// printf("%0*ds\n",num);
	// printf("%0.*ds\n",num);
	ft_printf("%-0.*ds\n",num);
	
}
