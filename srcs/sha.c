/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:53:03 by uhand             #+#    #+#             */
/*   Updated: 2020/11/27 22:19:10 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

int		ft_sha224(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_32	sha;
	t_read	rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha224_init(&sha, &rd);
	sha256_alg(&sha, &rd);
	sha224_output(&sha, digest);
	return (1);
}

int		ft_sha256(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_32	sha;
	t_read	rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha256_init(&sha, &rd);
	sha256_alg(&sha, &rd);
	sha256_output(&sha, digest);
	return (1);
}

int		ft_sha384(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_64	sha;
	t_read	rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha384_init(&sha, &rd);
	sha512_alg(&sha, &rd);
	sha384_output(&sha, digest);
	return (1);
}

int		ft_sha512(char const *message, t_prc_file *prc, int print, \
	char **digest)
{
	t_block_64	sha;
	t_read	rd;

	if (digest == NULL)
		return (-1);
	ft_bzero(&rd, sizeof(rd));
	rd.str_msg = message;
	rd.prc = prc;
	rd.print = print;
	sha512_init(&sha, &rd);
	sha512_alg(&sha, &rd);
	sha512_output(&sha, digest);
	return (1);
}
