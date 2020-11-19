/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:28:22 by uhand             #+#    #+#             */
/*   Updated: 2020/11/17 23:19:14 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*l_dst;
	unsigned long	*l_src;
	unsigned char	*c_dst;
	unsigned char	*c_src;
	size_t			i;

	l_dst = (unsigned long*)dst;
	l_src = (unsigned long*)src;
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	i = 0;
	while (i < (n / 8))
	{
		l_dst[i] = l_src[i];
		i++;
	}
	i *= 8;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
