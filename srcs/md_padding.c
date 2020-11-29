/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:57:53 by uhand             #+#    #+#             */
/*   Updated: 2020/11/29 21:47:11 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"

void	write_length(t_read *rd, t_common alg, unsigned char *block_ptr)
{
	unsigned long		*l_block_ptr;
	unsigned long long	*ll_block_ptr;

	if (alg.length_size == 8)
	{
		l_block_ptr = (unsigned long*)&block_ptr[alg.block_size - 8];
		l_block_ptr[0] = (unsigned long)(rd->read_count * 8);
		if (alg.reverse)
			flip_bytes((unsigned char *)&l_block_ptr[0], 8);
	}
	else
	{
		ll_block_ptr = (unsigned long long*)&block_ptr[alg.block_size - 16];
		ll_block_ptr[0] = rd->read_count * 8;
		if (alg.reverse)
			flip_bytes((unsigned char *)&ll_block_ptr[0], 16);
	}
}

int		uppend_block(t_read *rd, size_t i, t_common alg)
{
	unsigned char		*block_ptr;

	block_ptr = (unsigned char*)rd->x;
	if (!rd->start_uppending)
	{
		block_ptr[i] = 128;
		i++;
	}
	if ((alg.block_size - i) >= alg.length_size)
	{
		ft_bzero(&(block_ptr[i]), (alg.block_size - i));
		// ft_bzero(&(block_ptr[i]), (alg.block_size - (i + alg.length_size)));
		write_length(rd, alg, block_ptr);
		rd->finish_reading = 1;
	}
	else
	{
		ft_bzero(&(block_ptr[i]), (alg.block_size - i));
		rd->start_uppending = 1;
	}
	return (1);
}
