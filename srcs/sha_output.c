/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:17:36 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 13:52:42 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sha.h"

void	sha224_output(t_block_32 *sha, char **digest)
{
	ft_sprintf(digest, "%.8x%.8x%.8x%.8x%.8x%.8x%.8x", A, B, C, D, E, F, G);
}

void	sha256_output(t_block_32 *sha, char **digest)
{
	ft_sprintf(digest, "%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x", \
		A, B, C, D, E, F, G, H);
}

void	sha384_output(t_block_64 *sha, char **digest)
{
	ft_sprintf(digest, "%016llx%016llx%016llx%016llx%016llx%016llx", \
		A, B, C, D, E, F);
}

void	sha512_output(t_block_64 *sha, char **digest)
{
	ft_sprintf(digest, \
		"%016llx%016llx%016llx%016llx%016llx%016llx%016llx%016llx", \
		A, B, C, D, E, F, G, H);
}
