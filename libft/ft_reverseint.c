/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverseint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:00:23 by uhand             #+#    #+#             */
/*   Updated: 2019/10/03 19:18:05 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_reverseint(unsigned int i)
{
	unsigned char	a[4];

	a[0] = i & 255;
	a[1] = (i >> 8) & 255;
	a[2] = (i >> 16) & 255;
	a[3] = (i >> 24) & 255;
	return (((unsigned int)a[0] << 24) + ((unsigned int)a[1] << 16)
	+ ((unsigned int)a[2] << 8) + a[3]);
}
