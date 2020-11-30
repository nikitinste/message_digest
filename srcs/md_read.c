/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:20:54 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 12:06:10 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

static int	read_string(t_read *rd, t_common alg)
{
	size_t	i;
	char	*block_ptr;

	i = 0;
	if (rd->str_msg[0] == '\0')
		return (uppend_block(rd, i, alg));
	block_ptr = (char*)rd->x;
	while (rd->str_msg[0] != '\0' && i < (size_t)alg.block_size)
	{
		block_ptr[i] = rd->str_msg[0];
		rd->read_count++;
		rd->str_msg++;
		i++;
	}
	if (i < (size_t)alg.block_size)
		return (uppend_block(rd, i, alg));
	return (1);
}

static int	copy_block(t_read *rd, t_common alg)
{
	int		cpy_size;

	cpy_size = (rd->ret < alg.block_size) ? rd->ret : alg.block_size;
	ft_memcpy(rd->x, rd->ptr, cpy_size);
	if (rd->i + cpy_size >= (int)alg.read_size)
	{
		rd->i = 0;
		rd->ptr = NULL;
	}
	else
	{
		rd->i += cpy_size;
		rd->ptr += cpy_size;
	}
	rd->read_count += cpy_size;
	rd->ret -= cpy_size;
	if (cpy_size < alg.block_size)
		return (uppend_block(rd, cpy_size, alg));
	return (1);
}

static int	read_from_fd(t_read *rd, t_common alg)
{
	if (!rd->ptr && !(rd->ret = read(rd->prc->fd, &rd->buf, alg.read_size)))
		return (uppend_block(rd, rd->ret, alg));
	else if (rd->ptr)
		return (copy_block(rd, alg));
	else if (rd->ret && rd->ret != -1)
	{
		if (rd->print)
			write(1, rd->buf, rd->ret);
		rd->ptr = rd->buf;
		return (copy_block(rd, alg));
	}
	else if (rd->ret && rd->ret == -1)
	{
		ft_printf("ft_ssl: %s: %s: %s\n", rd->cmd_name, rd->prc->file_name, \
			strerror(errno));
		exit(-1);
	}
	return (0);
}

int			read_block(t_read *rd, t_common alg)
{
	if (rd->finish_reading)
		return (0);
	if (rd->str_msg)
		return (read_string(rd, alg));
	return (read_from_fd(rd, alg));
}
