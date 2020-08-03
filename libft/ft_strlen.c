/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 13:22:01 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlen(const char *c)
{
	int count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}
