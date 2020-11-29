/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:13:13 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 18:31:11 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

unsigned long	rotr_8(unsigned long val, unsigned int len)
{
	return ((val >> len) | (val << (64 - len)));
}

unsigned long	bsig0_8(unsigned long x)
{
	return (rotr_8(x, 28) ^ rotr_8(x, 34) ^ rotr_8(x, 39));
}

unsigned long	bsig1_8(unsigned long x)
{
	return (rotr_8(x, 14) ^ rotr_8(x, 18) ^ rotr_8(x, 41));
}

unsigned long	ssig0_8(unsigned long x)
{
	return (rotr_8(x, 1) ^ rotr_8(x, 8) ^ (x >> 7));
}

unsigned long	ssig1_8(unsigned long x)
{
	return (rotr_8(x, 19) ^ rotr_8(x, 61) ^ (x >> 6));
}
