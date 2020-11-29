/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:37:41 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 16:59:16 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

unsigned int	rotr_4(unsigned int val, unsigned int len)
{
	return ((val >> len) | (val << (32 - len)));
}

unsigned int	bsig0_4(unsigned int x)
{
	return (rotr_4(x, 2) ^ rotr_4(x, 13) ^ rotr_4(x, 22));
}

unsigned int	bsig1_4(unsigned int x)
{
	return (rotr_4(x, 6) ^ rotr_4(x, 11) ^ rotr_4(x, 25));
}

unsigned int	ssig0_4(unsigned int x)
{
	return (rotr_4(x, 7) ^ rotr_4(x, 18) ^ (x >> 3));
}

unsigned int	ssig1_4(unsigned int x)
{
	return (rotr_4(x, 17) ^ rotr_4(x, 19) ^ (x >> 10));
}
