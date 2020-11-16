/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:34:56 by uhand             #+#    #+#             */
/*   Updated: 2020/11/16 23:40:51 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/md5.h"

void	*message_append(char const *message)
{
	unsigned long	len;
	unsigned long	append_len;
	unsigned char	*buffer;
	unsigned long	*l_buf_ptr;

	len = (unsigned long)ft_strlen(message);
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

	ft_printf("\n%d\t%d\n", len, (len + append_len));
	return (buffer);
}

int		ft_md5(char const *message, char **digest)
{
	void	*flow;

	if (digest == NULL)
		return (-1);
	flow = message_append(message);

	free(flow);

	ft_sprintf(digest, "# md5 hash for \"%s\" #", message);
	return (1);
}
