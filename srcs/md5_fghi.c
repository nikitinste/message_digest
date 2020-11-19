/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_fghi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:51:31 by uhand             #+#    #+#             */
/*   Updated: 2020/11/18 17:12:29 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

unsigned int	f_ft(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) | (~x & z));
}

unsigned int	g_ft(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & z) | (y & ~z));
}

unsigned int	h_ft(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int	i_ft(unsigned int x, unsigned int y, unsigned int z)
{
	return (y ^ (x | ~z));
}

unsigned int	shift(unsigned int val, unsigned int len)
{
	unsigned int	reminder;

	len %= 32;
	reminder = val >> (32 - len);
	return ((val << len) | reminder);
}
