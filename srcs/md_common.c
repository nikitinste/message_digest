/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:06:30 by uhand             #+#    #+#             */
/*   Updated: 2020/11/28 17:31:12 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	set_read_buf_size(t_read *rd, t_common *alg)
{
	if (!rd->str_msg)
	{
		alg->read_size = READ_BUF_SIZE - (READ_BUF_SIZE % 64);
		if (alg->read_size < 256 || alg->read_size > 65536)
			end_with_message(\
				"ft_ssl: READ_BUF_SIZE must be between 256 and 65536", -1);
	}
}

void	flip_bytes(unsigned char *byte, int len)
{
	unsigned char	buffer;
	unsigned char	i;

	i = 0;
	while (i < (len / 2))
	{
		buffer = byte[i];
		byte[i] = byte[len - i - 1];
		byte[len - i - 1] = buffer;
		i++;
	}
}
