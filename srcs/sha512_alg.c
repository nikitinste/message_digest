/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:32:03 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 22:10:58 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static unsigned long	ch(unsigned long x, unsigned long y, unsigned long z)
{
	return ((x & y) ^ (~x & z));
}

static unsigned long	maj(unsigned long x, unsigned long y, unsigned long z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

static void	prepare_schedule(t_block_64 *sha)
{
	int				t;

	t = -1;
	while (++t < 16)
		flip_bytes((unsigned char *)&W[t], 8);
	t--;
	while (++t < 80)
		W[t] = ssig1_8(W[t - 2]) + W[t - 7] + ssig0_8(W[t - 15]) + W[t - 16];
}

static void	sha512_computations(t_block_64 *sha)
{
	int				t;
	unsigned long	t1;
	unsigned long	t2;

	t = -1;
	while (++t < 80)
	{
		t1 = H + bsig1_8(E) + ch(E, F, G) + K8[t] + W[t];
		t2 = bsig0_8(A) + maj(A, B, C);
		H = G;
	    G = F;
	    F = E;
	    E = D + t1;
	    D = C;
	    C = B;
	    B = A;
	    A = t1 + t2;
	}
}

void	sha512_alg(t_block_64 *sha, t_read *rd)
{
	t_common	alg;
	int			i;

	alg.block_size = 128;
	alg.length_size = 16;
	alg.reverse = 1;
	i = 0;
	set_read_buf_size(rd, &alg);
	while (read_block(rd, alg))
	{
		prepare_schedule(sha);
		ft_memcpy(&(sha->digest_buf[0]), &(sha->digest[0]), 64);
		sha512_computations(sha);
		A += AA;
		B += BB;
		C += CC;
		D += DD;
		E += EE;
		F += FF;
		G += GG;
		H += HH;
	}
}
