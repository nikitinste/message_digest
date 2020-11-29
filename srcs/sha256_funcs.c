/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:37:41 by uhand             #+#    #+#             */
/*   Updated: 2020/11/28 21:36:48 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

unsigned int	rotr(unsigned int val, unsigned int len)
{
	unsigned int	reminder;

	len %= 32;
	reminder = val << (32 - len);
	return ((val >> len) | reminder);
}

unsigned int	bsig0_4(unsigned int x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

unsigned int	bsig1_4(unsigned int x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

unsigned int	ssig0_4(unsigned int x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
}

unsigned int	ssig1_4(unsigned int x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
