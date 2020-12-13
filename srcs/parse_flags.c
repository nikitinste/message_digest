/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:07:31 by uhand             #+#    #+#             */
/*   Updated: 2020/12/13 21:28:25 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include <stdio.h>

static void	check_io_args(t_ssl *ssl, char const **arg, enum e_groups group)
{
	if (ssl->av[ssl->i][1] != '\0')
	{
		ssl->av[ssl->i]++;
		arg[0] = ssl->av[ssl->i];
	}
	else if ((ssl->i + 1) < ssl->ac)
		arg[0] = ssl->av[++ssl->i];
	else
		g_end_with_message[arg_error]((void*)ssl);
	if (group != md_group)
	{
		while (ssl->av[ssl->i][0] != '\0')
			ssl->av[ssl->i]++;
	}
}

static int	parse_group_flags(t_ssl *ssl, const char **args, \
	enum e_groups group, int flag_i)
{
	if (flag_i >= 0 && flag_i < FARG_LEN && FLAG && FLAG->group == group)
	{
		ssl->flags |= FLAG->num;
		if (FLAG->is_arg)
			check_io_args(ssl, &args[FLAG->arg_i], group);
		else
			ssl->av[ssl->i]++;
	}
	else
		return (0);
	return (1);
}

void		parse_md_flags(t_ssl *ssl)
{
	const char	*string[1];
	int		flag_i;

	string[0] = NULL;
	while (ssl->i < ssl->ac && ssl->av[ssl->i][0] == '-')
	{
		ssl->av[ssl->i]++;
		while (ssl->av[ssl->i][0] != '\0')
		{
			flag_i = ((ssl->av[ssl->i][0] - 112) * 4) + 1;
			if (parse_group_flags(ssl, string, md_group, flag_i))
			{
				if (string[0])
					return ;
			}
			else
				g_end_with_message[flag_error]((void*)ssl);
		}
		ssl->i++;
	}
}

void		parse_base_flags(t_ssl *ssl, const char **args)
{
	int		flag_i;

	while (ssl->i < ssl->ac && ssl->av[ssl->i][0] == '-')
	{
		ssl->av[ssl->i]++;
		while (ssl->av[ssl->i][0] != '\0')
		{
			flag_i = ssl->av[ssl->i][0] - 97;
			if (parse_group_flags(ssl, args, base_group, flag_i))
				continue ;
			else
				g_end_with_message[flag_error]((void*)ssl);
		}
		ssl->i++;
	}
}

void		parse_des_flags(t_ssl *ssl, const char **args)
{
	int		flag_i;

	while (ssl->i < ssl->ac && ssl->av[ssl->i][0] == '-')
	{
		ssl->av[ssl->i]++;
		while (ssl->av[ssl->i][0] != '\0')
		{
			flag_i = ssl->av[ssl->i][0] - 97;
			if (parse_group_flags(ssl, args, base_group, flag_i))
				continue ;
			else if (parse_group_flags(ssl, args, des_group, flag_i))
				continue ;
			else
				g_end_with_message[flag_error]((void*)ssl);
		}
		ssl->i++;
	}
}
