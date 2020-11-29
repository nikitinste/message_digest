/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:10:17 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 22:12:56 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static unsigned int	ch(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (~x & z));
}

static unsigned int	maj(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

static void	prepare_schedule(t_block_32 *sha)
{
	int				t;

	t = -1;
	while (++t < 16)
		flip_bytes((unsigned char *)&W[t], 4);
	t--;
	while (++t < 64)
		W[t] = ssig1_4(W[t - 2]) + W[t - 7] + ssig0_4(W[t - 15]) + W[t - 16];
}

static void	sha256_computations(t_block_32 *sha)
{
	int				t;
	unsigned int	t1;
	unsigned int	t2;

	t = -1;
	while (++t < 64)
	{
		t1 = H + bsig1_4(E) + ch(E, F, G) + K4[t] + W[t];
		t2 = bsig0_4(A) + maj(A, B, C);
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

void	sha256_alg(t_block_32 *sha, t_read *rd)
{
	t_common	alg;

	alg.block_size = 64;
	alg.length_size = 8;
	alg.reverse = 1;
	set_read_buf_size(rd, &alg);
	while (read_block(rd, alg))
	{
		prepare_schedule(sha);
		ft_memcpy(&(sha->digest_buf[0]), &(sha->digest[0]), 32);
		sha256_computations(sha);
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
