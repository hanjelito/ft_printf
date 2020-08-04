/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:52:01 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/04 12:05:16 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

void		*ft_calloc(size_t type, size_t numb);
void		ft_putnbr_fd(long n, int fd);
void		ft_putchar(char x, int fd);
void		ft_putchar_fd(char c, int fd);

size_t		ft_strlen(const char *c);
size_t		ft_intlen(long nb, int div);
int			ft_isalpha(int c);
int			ft_isdigit(char c);
int			ft_atoi(const char *str);

#endif
