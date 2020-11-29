/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:11:32 by uhand             #+#    #+#             */
/*   Updated: 2020/11/28 17:29:45 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

void	sha224_init(t_block_32 *sha, t_read *rd)
{
	A = 0xc1059ed8;
	B = 0x367cd507;
	C = 0x3070dd17;
	D = 0xf70e5939;
	E = 0xffc00b31;
	F = 0x68581511;
	G = 0x64f98fa7;
	H = 0xbefa4fa4;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha224];
}

void	sha256_init(t_block_32 *sha, t_read *rd)
{
	A = 0x6a09e667;
	B = 0xbb67ae85;
	C = 0x3c6ef372;
	D = 0xa54ff53a;
	E = 0x510e527f;
	F = 0x9b05688c;
	G = 0x1f83d9ab;
	H = 0x5be0cd19;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha256];
}

void	sha384_init(t_block_64 *sha, t_read *rd)
{
	A = 0xcbbb9d5dc1059ed8;
	B = 0x629a292a367cd507;
	C = 0x9159015a3070dd17;
	D = 0x152fecd8f70e5939;
	E = 0x67332667ffc00b31;
	F = 0x8eb44a8768581511;
	G = 0xdb0c2e0d64f98fa7;
	H = 0x47b5481dbefa4fa4;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha384];
}

void	sha512_init(t_block_64 *sha, t_read *rd)
{
	A = 0x6a09e667f3bcc908;
	B = 0xbb67ae8584caa73b;
	C = 0x3c6ef372fe94f82b;
	D = 0xa54ff53a5f1d36f1;
	E = 0x510e527fade682d1;
	F = 0x9b05688c2b3e6c1f;
	G = 0x1f83d9abfb41bd6b;
	H = 0x5be0cd19137e2179;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha512];
}
