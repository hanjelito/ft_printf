/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:52:01 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 19:20:19 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
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
	char		type;
	int			width;
	int			precision;
	int			len_str;
	int			aux;
	va_list		arg;
}				t_printf;

void			print_di(t_printf *data, int nb);
void			print_s(t_printf *data, char *str);
void			print_c(t_printf *data, int nb);
void			print_x(t_printf *data, unsigned int nb);
void			print_u(t_printf *data, unsigned int nb);
void			print_p(t_printf *data, char *ch);
void			print_ws(t_printf *data, int nb);

int				ft_pre_space_zero(int space, t_printf *data);
int				ft_pre_zero(int zero, t_printf *data);
void			ft_end_space(int space, t_printf *data);

int				ft_width1(int nb, t_printf *data);
void			ft_width2(int nb, t_printf *data);
void			ft_precision(t_printf *data);
void			ft_type_print(int nb, t_printf *data);
void			ft_setformat(t_printf *data);
void			ft_while(int space, int zero, t_printf *data, int nb);
int				ft_isformat(t_printf *data);

#endif
