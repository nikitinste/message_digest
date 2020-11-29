/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:13:13 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 22:16:42 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static unsigned long	rotr(unsigned long val, unsigned int len)
{
	return ((val >> len) | (val << (64 - len)));
}

unsigned long	bsig0_8(unsigned long x)
{
	return (rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39));
}

unsigned long	bsig1_8(unsigned long x)
{
	return (rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41));
}

unsigned long	ssig0_8(unsigned long x)
{
	return (rotr(x, 1) ^ rotr(x, 8) ^ (x >> 7));
}

unsigned long	ssig1_8(unsigned long x)
{
	return (rotr(x, 19) ^ rotr(x, 61) ^ (x >> 6));
}
