/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_to_eof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:31:39 by uhand             #+#    #+#             */
/*   Updated: 2020/11/20 15:23:24 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_to_eof.h"

int	ft_read_to_eof(const int fd, char **line)
{
	t_rte	args;

	if (fd < 0 || line == NULL)
		return (-1);
	ft_bzero(&args, sizeof(args));
	line[0] = NULL;
	while ((args.ret = read(fd, &args.buf_line, BUFF_SIZE)) > 0)
	{
		args.bufer = line[0];
		line[0] = malloc(args.read_count + args.ret);
		ft_memcpy((void*)&line[0][0], args.bufer, args.read_count);
		ft_memcpy((void*)&line[0][args.read_count], args.buf_line, args.ret);
		ft_strdel(&args.bufer);
		args.read_count += args.ret;
	}
	if (args.ret == -1)
	{
		ft_strdel(&args.bufer);
		return (-1);
	}
	return (args.read_count);
}
