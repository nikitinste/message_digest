/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_with_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:24:33 by uhand             #+#    #+#             */
/*   Updated: 2020/10/30 19:19:34 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		show_usage(void *params)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	exit((int)params);
}

int		show_command_error(void *params)
{
	int		i;

	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
Standard commands:\n\nMessage Digest commands:\n", (char*)params);
	i = -1;
	while (g_commands[++i])
		ft_printf("%s\n", g_commands[i]);
	ft_printf("\nCipher commands:\n");
	exit(-1);
}

int		show_flag_error(void *params)
{
	t_ssl	*ssl;

	ssl = (t_ssl*)params;
	ft_printf("ft_ssl: %s: illegal option -- %c\n\
usage: ft_ssl %s [-pqr] [-s string] [files ...]\n", COMMAND, \
		ssl->av[ssl->i][0], COMMAND);
	exit(-1);
}

int		show_string_error(void *params)
{
	t_ssl	*ssl;

	ssl = (t_ssl*)params;
	ft_printf("ft_ssl: %s: option requires an argument -- s\n\
usage: ft_ssl %s [-pqr] [-s string] [files ...]\n", COMMAND, COMMAND);
	exit(-1);
}

int		show_file_error(void *params)
{

	//
	exit((int)params);
}
