/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:56:51 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 22:47:41 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*cpy_dst;
	char const	*cpy_src;

	cpy_dst = dst;
	cpy_src = src;
	while (n--)
		*cpy_dst++ = *cpy_src++;
	return (dst);
}
