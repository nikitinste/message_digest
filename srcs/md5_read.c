/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:20:54 by uhand             #+#    #+#             */
/*   Updated: 2020/11/20 23:53:25 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/md5.h"

int		uppend_block(t_md *md, size_t i)
{
	unsigned char	*block_ptr;
	unsigned long	*l_block_ptr;

	block_ptr = (unsigned char*)X;
	if (!md->start_uppending)
	{
		block_ptr[i] = 128;
		i++;
	}
	if ((BLOCK_SIZE - i) > 8)
	{
		ft_bzero(&(block_ptr[i]), (BLOCK_SIZE - (i + 8)));
		l_block_ptr = (unsigned long*)&block_ptr[BLOCK_SIZE - 8];
		l_block_ptr[0] = md->read_count * 8;
		md->finish_reading = 1;
	}
	else
	{
		ft_bzero(&(block_ptr[i]), (BLOCK_SIZE - i));
		md->start_uppending = 1;
	}
	return (1);
}

int		read_string(t_md *md)
{
	size_t	i;
	char	*block_ptr;

	i = 0;
	if	(md->str_msg[0] == '\0')
		return (uppend_block(md, i));
	block_ptr = (char*)X;
	while (md->str_msg[0] != '\0' && i < 64)
	{
		block_ptr[i] = md->str_msg[0];
		md->read_count++;
		md->str_msg++;
		i++;
	}
	if (i < 64)
		return (uppend_block(md, i));
	return (1);
}

int		copy_block(t_md *md)
{
	int		cpy_size;

	cpy_size = (md->rd.ret < BLOCK_SIZE) ? md->rd.ret : BLOCK_SIZE;
	ft_memcpy(X, md->rd.ptr, cpy_size);
	if (md->rd.i + BLOCK_SIZE >= READ_BUF_SIZE)
	{
		md->rd.i = 0;
		md->rd.ptr = NULL;
	}
	else
	{
		md->rd.i += BLOCK_SIZE;
		md->rd.ptr += BLOCK_SIZE;
	}
	md->read_count += cpy_size;
	md->rd.ret -= cpy_size;
	if (cpy_size < BLOCK_SIZE)
		return (uppend_block(md, cpy_size));
	return (1);
}

int		read_from_fd(t_md *md)
{
	if (!md->rd.ptr && !(md->rd.ret = read(md->fd, &md->rd.buf, READ_BUF_SIZE)))
		return (uppend_block(md, md->rd.ret));
	else if (md->rd.ptr)
		return(copy_block(md));
	else if (md->rd.ret && md->rd.ret != -1)
	{
		md->rd.ptr = md->rd.buf;
		return(copy_block(md));
	}
	else if (md->rd.ret && md->rd.ret != -1)
	{
		ft_printf("ft_ssl: md5: %s: %s\n", "FILE_NAME", strerror(errno));
		exit (-1);
	}

	return (0);
}

int		read_block(t_md *md)
{
	if (md->finish_reading)
		return (0);
	if (md->str_msg)
		return (read_string(md));
	return (read_from_fd(md));
}
