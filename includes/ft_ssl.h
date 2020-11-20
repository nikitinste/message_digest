/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 22:27:35 by uhand             #+#    #+#             */
/*   Updated: 2020/11/20 22:36:21 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
#include <errno.h>
# include "../libft/libft.h"

# define COMMAND g_commands[ssl->cmd_ind]
# define FILE_NAME ssl->av[ssl->i]

typedef	int		(*t_end_wmsg)(void *params);
typedef int		(*t_get_hash)(char const *message, int fd, int print, \
	char **digest);

typedef union	u_lala
{
	unsigned long	a;
	unsigned int	b[2];
}				t_lala;

enum    e_commands
{
    md5,
    sha256
};

static char*		g_commands[] =
{
	"md5",
	"sha256",
	NULL
};

enum	e_flags
{
	echo = 1,
	quiet,
	reverse = 4,
	string_sum = 8
};

enum	e_error_functions
{
	usage,
	command_error,
	flag_error,
	string_error,
	file_error
};

typedef struct		s_prc_file
{
	char		*digest;
	char		*cmd_name;
	int			fd;
}					t_prc_file;

typedef struct		s_ssl
{
	int			flags;
	int			cmd_ind;
	int			i;
	int 		ac;
	char const	**av;
}				t_ssl;

typedef	int		(*t_end_wmsg)(void *params);

int 	show_usage(void *params);
int 	show_command_error(void *params);
int		show_flag_error(void *params);
int		show_string_error(void *params);
int 	show_file_error(void *params);
void	process_stdin(t_ssl *ssl);
void	process_string(t_ssl *ssl, int argc, char const **argv);
void	process_file(t_ssl *ssl, const char* filename);

int		ft_md5(char const *message, int fd, int print, char **digest);
int 	ft_sha256(char const *message, int fd, int print, char **digest);

static t_end_wmsg	g_end_with_message[] =
{
	&show_usage,
	&show_command_error,
	&show_flag_error,
	&show_string_error,
	&show_file_error
};

static t_get_hash	g_get_hash[] =
{
	&ft_md5,
	&ft_sha256
};

#endif
