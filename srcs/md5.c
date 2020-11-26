/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:34:56 by uhand             #+#    #+#             */
/*   Updated: 2020/11/26 01:03:24 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/md5.h"

void	md5_init(t_md *md, t_read *rd)
{
	A = 0x67452301;
	B = 0xEFCDAB89;
	C = 0x98BADCFE;
	D = 0x10325476;
	rd->x = (void*)md->x;
	rd->cmd_name = g_commands[md5];
}

void	flip_word(unsigned int *word)
{
	unsigned char *byte;
	unsigned char buffer;

	byte = (unsigned char *)word;
	buffer = byte[0];
	byte[0] = byte[3];
	byte[3] = buffer;
	buffer = byte[1];
	byte[1] = byte[2];
	byte[2] = buffer;
}

void	prepare_output(t_md *md, char **digest)
{
	flip_word(&A);
	flip_word(&B);
	flip_word(&C);
	flip_word(&D);
	ft_sprintf(digest, "%.8x%.8x%.8x%.8x", A, B, C, D);
}

int		ft_md5(char const *message, t_prc_file *prc, int print, char **digest)
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
