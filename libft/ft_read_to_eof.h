/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_to_eof.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:21:14 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 13:31:14 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_TO_EOF_H
# define FT_READ_TO_EOF_H

# include "libft.h"

# define BUFF_SIZE 10240

typedef struct	s_rte
{
	int		read_count;
	int		ret;
	char	*bufer;
	char	buf_line[BUFF_SIZE];
}				t_rte;

int				ft_read_to_eof(const int fd, char **line);
#endif
