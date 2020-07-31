/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:03 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/31 13:25:51 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ftext(t_printf *data)
{	
	
	if (*data->str == 'd' || *data->str == 'i')
		print_di(data, va_arg(data->arg, int));
	else if (*data->str == 's')
		print_s(data, va_arg(data->arg, char *));
	else if (*data->str == 'x' || *data->str == 'X')
		print_x(data, va_arg(data->arg, unsigned int), *data->str);
	else if (*data->str == 'c')
		print_c(data, va_arg(data->arg, int));
	else if (*data->str == 'p')
		print_p(data, va_arg(data->arg, char *));
	else if (*data->str == 'u')
		print_u(data, va_arg(data->arg, int));
	else if (*data->str == '%')
		print_ws(data, '%');
}

void		ft_setformat(t_printf *data)
{
	int nb;	
	data->width 		= 0;
	data->precision 	= 0;
	data->tab 			= ' ';
	data->zero_space 	= ' ';
	data->dot 			= ' ';
	while (!ft_isalpha(*data->str))
	{
		++data->str;
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
	t_printf	*data;
	if (!(data = ft_calloc(sizeof(t_printf), 1)))
		return (0);
	data->str = (char *)format;
	va_start(data->arg, format);
	ft_formatletter(data);
	va_end(data->arg);
	free(data);
	return (data->len_str);
}


int main(void)
{

// 	// ft_printf("%-05d\n",-7);
// 	// ft_printf("%-05d\n",-7);
// 	//    printf("%-05d\n",-7);
// 	// ft_printf("%05d\n",7);
// 	// ft_printf("%5d\n",7);
	// printf("\n|%d|\n", ft_printf("%07d\n", -54));
	// printf("\n|%d|\n" ,   printf("%07d\n", -54));
// 	printf("\n|%d|\n", ft_printf("%32s", NULL));
// ft_printf("%c", "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%");

ft_printf("%07i\n", -54);
ft_printf("%04i\n", -532);
ft_printf("%04i\n", -4825);
ft_printf("%7i\n", -14);
ft_printf("%-7i\n", -14);
ft_printf("%10.5i\n", -216);
ft_printf("%.6d\n", -3);



//    printf("%d\n", 11);
// ft_printf("%-07s\n", "hello");
//    printf("%-07s\n", "hello");
}
