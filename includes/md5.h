/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:21:51 by uhand             #+#    #+#             */
/*   Updated: 2020/11/27 21:02:38 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

#include "../includes/ft_ssl.h"

# define A md->digest[0]
# define B md->digest[1]
# define C md->digest[2]
# define D md->digest[3]
# define AA md->digest_buf[0]
# define BB md->digest_buf[1]
# define CC md->digest_buf[2]
# define DD md->digest_buf[3]
# define X md->x
# define T g_t



typedef struct		s_md
{
	unsigned int	digest[4];
	unsigned int	digest_buf[4];
	unsigned int	x[16];
}					t_md;

static unsigned int	g_t[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
	0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
	0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
	0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
	0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};


unsigned int	f_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	g_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	h_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	i_ft(unsigned int x, unsigned int y, unsigned int z);
unsigned int	rotl(unsigned int val, unsigned int len);
void			md5_alg(t_md *md, t_read *rd);

#endif
