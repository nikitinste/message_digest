/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:21:51 by uhand             #+#    #+#             */
/*   Updated: 2020/11/18 00:46:19 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <math.h>
#include "../includes/ft_ssl.h"

# define A md->digest[0]
# define B md->digest[1]
# define C md->digest[2]
# define D md->digest[3]
# define AA md->digest_buf[0]
# define BB md->digest_buf[1]
# define CC md->digest_buf[2]
# define DD md->digest_buf[3]
# define T md->t
# define X md->x

typedef struct		s_md
{
	void			*flow;
	unsigned long	blocks_count;
	unsigned int	digest[4];
	unsigned int	digest_buf[4];
	unsigned int	t[64];
	unsigned int	x[16];
}					t_md;


unsigned int	f_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	g_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	h_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	i_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	shift(unsigned int val, unsigned int len);
void			md5_alg(t_md *md);

#endif
