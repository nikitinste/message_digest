/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_512_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:35:17 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 12:19:18 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

static void	sha512_bonus_output(t_block_64 *sha, char **digest, \
	enum e_commands cmd)
{
	if (cmd == sha512_224)
		ft_sprintf(digest, "%016llx%016llx%016llx%08llx", A, B, C, D >> 32);
	else if (cmd == sha512_256)
		ft_sprintf(digest, "%016llx%016llx%016llx%016llx", A, B, C, D);
}

static void	sha512_224_init(t_block_64 *sha, t_read *rd)
{
	A = 0x8C3D37C819544DA2;
	B = 0x73E1996689DCD4D6;
	C = 0x1DFAB7AE32FF9C82;
	D = 0x679DD514582F9FCF;
	E = 0x0F6D2B697BD44DA8;
	F = 0x77E36F7304C48942;
	G = 0x3F9D85A86A1D36C8;
	H = 0x1112E6AD91D692A1;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha512_224];
}

static void	sha512_256_init(t_block_64 *sha, t_read *rd)
{
	A = 0x22312194FC2BF72C;
	B = 0x9F555FA3C84C64C2;
	C = 0x2393B86B6F53B151;
	D = 0x963877195940EABD;
	E = 0x96283EE2A88EFFE3;
	F = 0xBE5E1E2553863992;
	G = 0x2B0199FC2C85B8AA;
	H = 0x0EB72DDC81C52CA2;
	rd->x = (void*)sha->w;
	rd->cmd_name = g_commands[sha512_256];
}

int			ft_sha512_224(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_64	sha;
	t_read		rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha512_224_init(&sha, &rd);
	sha512_alg(&sha, &rd);
	sha512_bonus_output(&sha, digest, sha512_224);
	return (1);
}

int			ft_sha512_256(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_64	sha;
	t_read		rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha512_256_init(&sha, &rd);
	sha512_alg(&sha, &rd);
	sha512_bonus_output(&sha, digest, sha512_256);
	return (1);
}
