/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:13:13 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 11:54:15 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static uint64_t	rotr(uint64_t val, unsigned int len)
{
	return ((val >> len) | (val << (64 - len)));
}

uint64_t		bsig0_8(uint64_t x)
{
	return (rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39));
}

uint64_t		bsig1_8(uint64_t x)
{
	return (rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41));
}

uint64_t		ssig0_8(uint64_t x)
{
	return (rotr(x, 1) ^ rotr(x, 8) ^ (x >> 7));
}

uint64_t		ssig1_8(uint64_t x)
{
	return (rotr(x, 19) ^ rotr(x, 61) ^ (x >> 6));
}
