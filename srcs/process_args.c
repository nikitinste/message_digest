/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:01:53 by uhand             #+#    #+#             */
/*   Updated: 2020/11/02 13:12:16 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include <errno.h>


void	process_stdin(t_ssl *ssl)
{
	char	*message;
	char	*digest;

	if (!ft_read_to_eof(0, &message))
		return ;
	ft_printf("%s", message);
	g_get_hash[ssl->cmd_ind](message, &digest);
	ft_printf("%s\n", digest);
	ft_strdel(&message);
	ft_strdel(&digest);
}

void	process_string(t_ssl *ssl, int argc, char const **argv)
{
	char	*digest;
	char	*cmd_name;

	if (argv[ssl->i][0] != '\0')
		g_get_hash[ssl->cmd_ind](argv[ssl->i], &digest);
	else if (++ssl->i < argc)
		g_get_hash[ssl->cmd_ind](argv[ssl->i], &digest);
	else
		g_end_with_message[string_error]((void*)ssl);
	cmd_name = NULL;
	if (ssl->flags & quiet)
		ft_printf("%s\n", digest);
	else if (ssl->flags & reverse)
		ft_printf("%s \"%s\"\n", digest, argv[ssl->i]);
	else
	{
		cmd_name = ft_strmap(COMMAND, &ft_toupchar);
		ft_printf("%s (\"%s\") = %s\n", cmd_name, argv[ssl->i], digest);
	}
	ft_strdel(&digest);
	ft_strdel(&cmd_name);
	ssl->i++;
}

void	process_file(t_ssl *ssl, const char* filename)
{
	t_prc_file	prc;

	ft_bzero(&prc, sizeof(prc));
	prc.fd = open(FILE_NAME , O_RDONLY);
	if (prc.fd == -1)
	{
		ft_printf("ft_ssl: %s: %s: %s\n", COMMAND, FILE_NAME, strerror(errno));
		return ;
	}
	if (!ft_read_to_eof(prc.fd, &prc.message))
		return ;// show read file error message
	g_get_hash[ssl->cmd_ind](prc.message, &prc.digest);
	if (ssl->flags & quiet)
		ft_printf("%s\n", prc.digest);
	else if (ssl->flags & reverse)
		ft_printf("%s %s\n", prc.digest, FILE_NAME);
	else
	{
		prc.cmd_name = ft_strmap(COMMAND, &ft_toupchar);
		ft_printf("%s (%s) = %s\n", prc.cmd_name, FILE_NAME, prc.digest);
	}
	ft_strdel(&prc.message);
	ft_strdel(&prc.digest);
	ft_strdel(&prc.cmd_name);
}
