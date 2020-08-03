/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:51:33 by juan-gon          #+#    #+#             */
/*   Updated: 2020/08/03 13:21:43 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

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
