/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islitendian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:49:57 by uhand             #+#    #+#             */
/*   Updated: 2019/10/03 18:59:12 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_islitendian(void)
{
	unsigned short	i;
	unsigned char	*c;

	i = 1;
	c = (unsigned char*)&i;
	if (c[0] == 1)
		return (1);
	return (0);
}
