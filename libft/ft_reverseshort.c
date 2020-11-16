/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverseshort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:14:33 by uhand             #+#    #+#             */
/*   Updated: 2019/10/03 19:18:21 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_reverseshort(unsigned int i)
{
	unsigned char	a[2];

	a[0] = i & 255;
	a[1] = (i >> 8) & 255;
	return ((unsigned short)(a[0] << 8) + a[1]);
}
