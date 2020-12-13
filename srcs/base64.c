/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:58:54 by uhand             #+#    #+#             */
/*   Updated: 2020/12/11 23:29:12 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"



int		ft_base64(t_ssl *ssl)
{
	t_base	base;

	ft_bzero(&base, sizeof(base));
	parse_base_flags(ssl, base.args);
	if ((ssl->flags & decode) && !(ssl->flags & encode))
		base.mode = decode;
	else if ((ssl->flags & decode) && (ssl->flags & encode))
		end_with_message("ft_ssl: base64: mutually exclusive options -- d | e\n\
usage: ft_ssl base64 [-d|e] [-i in_file] [-o out_file]", -1);
	ft_printf("base64:\n");
	if (ssl->flags & decode)
		ft_printf("decode\n");
	if (ssl->flags & encode)
		ft_printf("encode\n");
	if (base.args[i_arg])
		ft_printf("input:\t%s\n", base.args[i_arg]);
	if (base.args[o_arg])
		ft_printf("output:\t%s\n", base.args[o_arg]);
	return (1);
}
