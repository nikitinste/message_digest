/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:34:56 by uhand             #+#    #+#             */
/*   Updated: 2020/11/19 00:03:29 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/md5.h"

void	*message_append(char const *message, size_t len, t_md *md)
{
	unsigned long	append_len;
	unsigned char	*buffer;
	unsigned long	*l_buf_ptr;

	if ((len + 9) % 64 != 0)
		append_len = 9 + (64 - ((len + 9) % 64));
	else
		append_len = 9;
	buffer = malloc(len + append_len);
	ft_memcpy((void*)buffer, message, len);
	buffer[len] = 128;
	ft_memset((void*)&buffer[len + 1], 0, (append_len - 9));
	l_buf_ptr = (unsigned long*)buffer;
	l_buf_ptr[((len + append_len) / 8) - 1] = len * 8;
	md->blocks_count = (len + append_len) / 64;
	return (buffer);
}

void	const_init(t_md *md)
{
	int		i;

	A = 0x67452301;
	B = 0xEFCDAB89;
	C = 0x98BADCFE;
	D = 0x10325476;
	i = 0;
	while (++i <= 64)
		T[i - 1] = 4294967296 * fabs(sin(i));
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

int		ft_md5(char const *message, size_t msg_size, char **digest)
{
	t_md	md;

	if (digest == NULL)
		return (-1);

	md.flow = message_append(message, msg_size, &md);
	const_init(&md);
	md5_alg(&md);
	prepare_output(&md, digest);
	free(md.flow);
	return (1);
}
