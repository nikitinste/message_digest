/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:16:17 by uhand             #+#    #+#             */
/*   Updated: 2020/12/11 20:20:12 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	init_flag_parsing(t_ssl *ssl)
{
	int		i;

	i = 0;
	while (i < 13)
	{
		ssl->flag_args[g_flags[i].ind] = &g_flags[i];
		i++;
	}
}

static int	process_md(t_ssl *ssl)
{
	if (ssl->ac > 2)
		parse_md_flags(ssl);
	if (ssl->flags & echo)
		process_stdin(ssl);
	if (ssl->flags & string_sum)
		process_string(ssl);
	if (!(ssl->flags & echo) && !(ssl->flags & string_sum) && ssl->i >= ssl->ac)
		process_stdin(ssl);
	ssl->i--;
	while (++ssl->i < ssl->ac)
		process_file(ssl);
	return (1);
}

static int	parse_args(t_ssl *ssl)
{
	ssl->i = -1;
	ssl->cmd_ind = -1;
	while (g_commands[++ssl->i] != NULL)
		if (ft_strcmp(ssl->av[1], g_commands[ssl->i]) == 0)
		{
			ssl->cmd_ind = ssl->i;
			break ;
		}
	if (ssl->cmd_ind == -1)
		g_end_with_message[command_error]((void*)ssl->av[1]);
	ssl->i = 2;
	if (CMD_I >= 0 && CMD_I <= 6)
		return (process_md(ssl));
	return (g_get_ssl[CMD_I - 7](ssl));
}

int			main(int argc, char const **argv)
{
	t_ssl	ssl;

	if (argc < 2)
		g_end_with_message[usage](0);
	ft_bzero(&ssl, sizeof(ssl));
	ssl.ac = argc;
	ssl.av = argv;
	init_flag_parsing(&ssl);
	parse_args(&ssl);
	return (0);
}
