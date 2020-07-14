/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:03 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/14 13:29:43 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ftext(t_printf *data)
{	
	
	if (*data->str == 'd' || *data->str == 'i')
		ft_spacex(data, va_arg(data->arg, int));
	 	//print_d(data);
	// else if (*data->str == 's')
	// 	print_s(data);
	// else if (*data->str == 'x' || *data->str == 'X')
	// 	print_x(data);
	// else if (*data->str == 'c')
	// 	print_c(data);
	// else if (*data->str == '%')
	// 	print_porc(data);
	// else if (is_number(*data->str) == 1 || *data->str == ' ' || *data->str == '-')
	// 	print_ws(data);
	// else if (*data->str == 'u')
	// 	print_u(data);
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
		// ft_pick(nb, data);
		ft_type_print(nb, data);
		if (*data->str == '%')
			break ;
	}
}

void		ft_formatletter(t_printf *data)
{
	data->len_str = 0;
	while (*data->str)
	{
		if (*data->str == '%')
		{
			ft_setformat(data);
			ftext(data);
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

	int num = 12; 
	// int num2 = 12345; 
	// printf("%d\n",num2); 
	printf("%.0*d\n",num);
	// printf("%0.*ds\n",num);
	// printf("%------0--------.*ds\n",num);
	// printf("%.090d\n",num);
	// printf("%0.*ds\n", 8);
	
}
