/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:59:56 by uhand             #+#    #+#             */
/*   Updated: 2020/12/11 23:28:55 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_args(t_ssl *ssl, t_des *des, char *cmd)
{
	ft_printf("%s:\n", cmd);
	if (ssl->flags & decode)
		ft_printf("decode\n");
	if (ssl->flags & encode)
		ft_printf("encode\n");
	if (ssl->flags & base)
		ft_printf("base\n");
	if (des->args[i_arg])
		ft_printf("input:\t%s\n", des->args[i_arg]);
	if (des->args[o_arg])
		ft_printf("output:\t%s\n", des->args[o_arg]);
	if (des->args[k_arg])
		ft_printf("key:\t%s\n", des->args[k_arg]);
	if (des->args[p_arg])
		ft_printf("pass:\t%s\n", des->args[p_arg]);
	if (des->args[s_arg])
		ft_printf("salt:\t%s\n", des->args[s_arg]);
	if (des->args[v_arg])
		ft_printf("vector:\t%s\n", des->args[v_arg]);
}

int		ft_des(t_ssl *ssl)
{
	t_des	des;

	ft_bzero(&des, sizeof(des));
	parse_des_flags(ssl, des.args);
	print_args(ssl, &des, "des");
	return (1);
}

int		ft_des_ecb(t_ssl *ssl)
{
	t_des	des;

	ft_bzero(&des, sizeof(des));
	parse_des_flags(ssl, des.args);
	print_args(ssl, &des, "des-ecb");
	return (1);
}

int		ft_des_cbc(t_ssl *ssl)
{
	t_des	des;

	ft_bzero(&des, sizeof(des));
	parse_des_flags(ssl, des.args);
	print_args(ssl, &des, "des-cbc");
	return (1);
}
