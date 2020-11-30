/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:16:17 by uhand             #+#    #+#             */
/*   Updated: 2020/11/30 11:58:46 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	parse_flags(t_ssl *ssl, int argc, char const **argv)
{
	while (ssl->i < argc && argv[ssl->i][0] == '-')
	{
		argv[ssl->i]++;
		while (argv[ssl->i][0] != '\0')
		{
			if (argv[ssl->i][0] == 'p')
				ssl->flags |= echo;
			else if (argv[ssl->i][0] == 'q')
				ssl->flags |= quiet;
			else if (argv[ssl->i][0] == 'r')
				ssl->flags |= reverse;
			else if (argv[ssl->i][0] == 's')
			{
				ssl->flags |= string_sum;
				argv[ssl->i]++;
				return ;
			}
			else
				g_end_with_message[flag_error]((void*)ssl);
			argv[ssl->i]++;
		}
		ssl->i++;
	}
}

int		parse_args(t_ssl *ssl, int argc, char const **argv)
{
	ssl->i = -1;
	ssl->cmd_ind = -1;
	while (g_commands[++ssl->i] != NULL)
		if (ft_strcmp(argv[1], g_commands[ssl->i]) == 0)
		{
			ssl->cmd_ind = ssl->i;
			break ;
		}
	if (ssl->cmd_ind == -1)
		g_end_with_message[command_error]((void*)argv[1]);
	ssl->i = 2;
	if (argc > 2)
		parse_flags(ssl, argc, argv);
	if (ssl->flags & echo)
		process_stdin(ssl);
	if (ssl->flags & string_sum)
		process_string(ssl, argc, argv);
	if (!(ssl->flags & echo) && !(ssl->flags & string_sum) && ssl->i >= argc)
		process_stdin(ssl);
	ssl->i--;
	while (++ssl->i < argc)
		process_file(ssl);
	return (1);
}

int		main(int argc, char const **argv)
{
	t_ssl	ssl;

	if (argc < 2)
		g_end_with_message[usage](0);
	ft_bzero(&ssl, sizeof(ssl));
	ssl.ac = argc;
	ssl.av = argv;
	parse_args(&ssl, argc, argv);
	return (0);
}
