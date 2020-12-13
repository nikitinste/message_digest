/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_with_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:24:33 by uhand             #+#    #+#             */
/*   Updated: 2020/12/13 23:44:25 by uhand            ###   ########.fr       */
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
	while (++i <= 6)
		ft_printf("%s\n", g_commands[i]);
	ft_printf("\nCipher commands:\n");
	i--;
	while (g_commands[++i])
		ft_printf("%s\n", g_commands[i]);
	exit(-1);
}

int		show_flag_error(void *params)
{
	t_ssl	*ssl;
	int		usage_ind;

	ssl = (t_ssl*)params;
	usage_ind = get_group_ind(CMD_I);
	ft_printf("ft_ssl: %s: illegal option -- %c\n", COMMAND,
		*(ssl->av[ssl->i]));
	ft_printf("usage: ft_ssl %s %s\n", COMMAND, g_usage[usage_ind]);
	exit(-1);
}

int		show_arg_error(void *params)
{
	t_ssl	*ssl;
	int		usage_ind;

	ssl = (t_ssl*)params;
	usage_ind = get_group_ind(CMD_I);
	ft_printf("ft_ssl: %s: option requires an argument -- %c\n", COMMAND, \
		ssl->av[ssl->i][0]);
	ft_printf("usage: ft_ssl %s %s\n", COMMAND, g_usage[usage_ind]);
	exit(-1);
}

int		end_with_message(char *message, void *params, int ret)
{
	t_ssl	*ssl;
	int		usage_ind;

	if (!params)
	{
		ft_printf("%s\n", message);
		exit(ret);
	}
	ssl = (t_ssl*)params;
	usage_ind = get_group_ind(CMD_I);
	ft_printf("ft_ssl: %s: %s\n", COMMAND, message);
	ft_printf("usage: ft_ssl %s %s\n", COMMAND, g_usage[usage_ind]);
	exit(ret);
}
