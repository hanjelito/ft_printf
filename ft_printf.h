/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:52:01 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/28 18:19:26 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_printf
{
	char		*str;
	char		zero_space;
	char		tab;
	char		dot;
	int			width;
	int			precision;
	int			len_str;
	int			aux;
	va_list		arg;
} 				t_printf;

void		print_di(t_printf *data, int nb);
void		print_s(t_printf *data, char *str);
void		print_c(t_printf *data, int nb);
void		print_x(t_printf *data, unsigned int nb, char type);
void		print_u(t_printf *format, unsigned int nb);

void ft_tab(int nb, t_printf *data);
void ft_width(int nb, t_printf *data);
void ft_precision(t_printf *data);
void ft_zero_space(t_printf *data);


void 		*ft_calloc(size_t type, size_t numb);
void		ft_setformat(t_printf *data);
void		ft_type_print(int nb, t_printf *data);
void		ft_putnbr_fd(long n, int fd);
void		ft_putchar(char x, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_while(int space, int zero, t_printf *data, int nb);
size_t	ft_strlen(const char *c);
size_t		ft_intlen(long nb, int div);
int	ft_isalpha(int c);
int ft_isdigit(char c);
int	ft_atoi(const char *str);
int ft_isformat(t_printf *data);

#endif