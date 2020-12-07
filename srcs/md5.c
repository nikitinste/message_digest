/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:34:56 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 13:54:08 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

static void	md5_init(t_md *md, t_read *rd)
{
	A = 0x67452301;
	B = 0xEFCDAB89;
	C = 0x98BADCFE;
	D = 0x10325476;
	rd->x = (void*)md->x;
}

static void	prepare_output(t_md *md, char **digest)
{
	flip_bytes((unsigned char *)&A, 4);
	flip_bytes((unsigned char *)&B, 4);
	flip_bytes((unsigned char *)&C, 4);
	flip_bytes((unsigned char *)&D, 4);
	ft_sprintf(digest, "%.8x%.8x%.8x%.8x", A, B, C, D);
}

int			ft_md5(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_md	md;
	t_read	rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	md5_init(&md, &rd);
	md5_alg(&md, &rd);
	prepare_output(&md, digest);
	return (1);
}
