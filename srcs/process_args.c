/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:01:53 by uhand             #+#    #+#             */
/*   Updated: 2020/12/11 20:18:33 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	process_stdin(t_ssl *ssl)
{
	t_prc_file	prc;

	prc.file_name = "STDIN";
	prc.fd = 0;
	g_get_hash[ssl->cmd_ind](NULL, &prc, (ssl->flags & echo), &prc.digest);
	ft_printf("%s\n", prc.digest);
	ft_strdel(&prc.digest);
}

void	process_string(t_ssl *ssl)
{
	char	*digest;
	char	*cmd_name;

	if (ssl->av[ssl->i][1] != '\0')
		g_get_hash[ssl->cmd_ind](ssl->av[ssl->i], NULL, 0, &digest);
	else if ((ssl->i + 1) < ssl->ac)
		g_get_hash[ssl->cmd_ind](ssl->av[++ssl->i], NULL, 0, &digest);
	else
		g_end_with_message[arg_error]((void*)ssl);
	cmd_name = NULL;
	if (ssl->flags & quiet)
		ft_printf("%s\n", digest);
	else if (ssl->flags & reverse)
		ft_printf("%s \"%s\"\n", digest, ssl->av[ssl->i]);
	else
	{
		cmd_name = ft_strmap(COMMAND, &ft_toupchar);
		ft_printf("%s (\"%s\") = %s\n", cmd_name, ssl->av[ssl->i], digest);
	}
	ft_strdel(&digest);
	ft_strdel(&cmd_name);
	ssl->i++;
}

void	process_file(t_ssl *ssl)
{
	t_prc_file	prc;

	ft_bzero(&prc, sizeof(prc));
	prc.fd = open(FILE_NAME, O_RDONLY);
	if (prc.fd == -1)
	{
		ft_printf("ft_ssl: %s: %s: %s\n", COMMAND, FILE_NAME, strerror(errno));
		return ;
	}
	prc.file_name = FILE_NAME;
	g_get_hash[ssl->cmd_ind](NULL, &prc, 0, &prc.digest);
	if (ssl->flags & quiet)
		ft_printf("%s\n", prc.digest);
	else if (ssl->flags & reverse)
		ft_printf("%s %s\n", prc.digest, FILE_NAME);
	else
	{
		prc.cmd_name = ft_strmap(COMMAND, &ft_toupchar);
		ft_printf("%s (%s) = %s\n", prc.cmd_name, FILE_NAME, prc.digest);
	}
	close(prc.fd);
	ft_strdel(&prc.digest);
	ft_strdel(&prc.cmd_name);
}
