/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:52:01 by juan-gon          #+#    #+#             */
/*   Updated: 2020/07/08 09:54:55 by juan-gon         ###   ########.fr       */
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

void		ft_setformat(t_printf *data);
void		ft_pick(int nb, t_printf *data);
void		ft_pick2(int nb, t_printf *data);
int	ft_isalpha(int c);
int ft_isdigit(char c);
int	ft_atoi(const char *str);
int ft_isformat(t_printf *data);

#endif