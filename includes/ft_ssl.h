/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 22:27:35 by uhand             #+#    #+#             */
/*   Updated: 2020/11/26 19:30:39 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
#include <errno.h>
# include "../libft/libft.h"

# define READ_BUF_SIZE 10240

# define COMMAND g_commands[ssl->cmd_ind]
# define FILE_NAME ssl->av[ssl->i]

typedef struct	s_prc_file t_prc_file;
typedef	int		(*t_end_wmsg)(void *params);
typedef int		(*t_get_hash)(char const *message, t_prc_file *prc, int print, \
	char **digest);

typedef union	u_lala
{
	unsigned long	a;
	unsigned int	b[2];
}				t_lala;

enum    		e_commands
{
    md5,
	sha224,
    sha256,
	sha384,
	sha512
};

static			char* g_commands[] =
{
	"md5",
	"sha224",
	"sha256",
	"sha384",
	"sha512",
	NULL
};

enum			e_flags
{
	echo = 1,
	quiet,
	reverse = 4,
	string_sum = 8
};

enum			e_error_functions
{
	usage,
	command_error,
	flag_error,
	string_error,
	file_error
};

struct			s_prc_file
{
	char				*digest;
	char				*cmd_name;
	const char			*file_name;
	int					fd;
};

typedef struct	s_ssl
{
	int					flags;
	int					cmd_ind;
	int					i;
	int 				ac;
	char const			**av;
}				t_ssl;

typedef struct		s_read
{
	int					i;
	int					ret;
	unsigned char		*ptr;
	unsigned char		buf[READ_BUF_SIZE];
	char const 			*str_msg;
	int					print;
	unsigned long long	read_count;
	int					start_uppending;
	int					finish_reading;
	t_prc_file			*prc;
	void				*x;
	char				*cmd_name;
}					t_read;

typedef struct		s_common
{
	int					block_size;
	int					length_size;
	int					read_size;
}					t_common;

typedef	int		(*t_end_wmsg)(void *params);

int 	show_usage(void *params);
int 	show_command_error(void *params);
int		show_flag_error(void *params);
int		show_string_error(void *params);
int 	show_file_error(void *params);
void	process_stdin(t_ssl *ssl);
void	process_string(t_ssl *ssl, int argc, char const **argv);
void	process_file(t_ssl *ssl, const char* filename);

void	common_init(t_read *rd);
int		read_block(t_read *rd, t_common alg);
int		uppend_block(t_read *rd, size_t i, t_common alg);

int		ft_md5(char const *message, t_prc_file *prc, int print, char **digest);
int 	ft_sha224(char const *message, t_prc_file *prc, int print, \
	char **digest);
int 	ft_sha256(char const *message, t_prc_file *prc, int print, \
	char **digest);
int 	ft_sha384(char const *message, t_prc_file *prc, int print, \
	char **digest);
int 	ft_sha512(char const *message, t_prc_file *prc, int print, \
	char **digest);

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
	&ft_sha256,
	&ft_sha256,
	&ft_sha512,
	&ft_sha512
};

#endif
