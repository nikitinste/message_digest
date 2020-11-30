/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:37:41 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 12:21:12 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static uint32_t	rotr(uint32_t val, uint32_t len)
{
	return ((val >> len) | (val << (32 - len)));
}

uint32_t		bsig0_4(uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

uint32_t		bsig1_4(uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

uint32_t		ssig0_4(uint32_t x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
}

uint32_t		ssig1_4(uint32_t x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
