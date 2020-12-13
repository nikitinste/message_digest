/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uhand <uhand@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:22:51 by uhand             #+#    #+#             */
/*   Updated: 2020/12/13 23:42:21 by uhand            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

# define READ_BUF_SIZE 16384
# define COMMAND g_commands[ssl->cmd_ind]
# define CMD_I ssl->cmd_ind
# define FILE_NAME ssl->av[ssl->i]
# define FLAG ssl->flag_args[flag_i]
# define FARG_LEN 22

typedef struct s_prc_file	t_prc_file;
typedef struct s_ssl		t_ssl;
typedef struct s_flag		t_flag;
typedef	int					(*t_end_wmsg)(void *params);
typedef int					(*t_get_hash)(char const *message, \
	t_prc_file *prc, int print, char **digest);
typedef int					(*t_get_ssl)(t_ssl *ssl);

enum				e_commands
{
	md5,
	sha224,
	sha256,
	sha384,
	sha512,
	sha512_224,
	sha512_256,
	base64,
	des,
	des_ecb,
	des_cbc
};

static char			*g_commands[12] =
{
	"md5",
	"sha224",
	"sha256",
	"sha384",
	"sha512",
	"sha512-224",
	"sha512-256",
	"base64",
	"des",
	"des-ecb",
	"des-cbc",
	NULL
};

enum					e_groups
{
	md_group,
	base_group,
	des_group
};

static char			*g_usage[3] =
{
	"[-pqr] [-s string] [files ...]",
	"[-d|e] [-i in_file] [-o out_file]",
	"[-a] [-d|e] [-i in_file] [-o out_file] [-k key] [-p pass] [-s salt] \
[-v vector]"
};

enum					e_md_flags
{
	echo = 1,
	quiet,
	reverse = 4,
	string_sum = 8
};

enum					e_base_flags
{
	decode = 1,
	encode,
	input = 4,
	output = 8
};

enum					e_des_flags
{
	base = 16,
	key = 32,
	pass = 64,
	salt = 128,
	vector = 256
};

enum					e_error_functions
{
	usage,
	command_error,
	flag_error,
	arg_error
};

struct					s_prc_file
{
	char			*digest;
	char			*cmd_name;
	const char		*file_name;
	int				fd;
};

struct					s_ssl
{
	int				flags;
	int				cmd_ind;
	int				i;
	int				ac;
	char const		**av;
	t_flag 			*flag_args[FARG_LEN];
};

typedef struct			s_read
{
	int				i;
	int				ret;
	unsigned char	*ptr;
	unsigned char	buf[READ_BUF_SIZE];
	char const		*str_msg;
	int				print;
	__uint128_t		read_count;
	int				start_uppending;
	int				finish_reading;
	t_prc_file		*prc;
	void			*x;
	char			*cmd_name;
}						t_read;

typedef struct			s_common
{
	int				block_size;
	int				length_size;
	uint32_t		read_size;
	int				reverse;
}						t_common;

typedef struct			s_base
{
	int				mode;
	const char		*args[2];
}						t_base;

typedef struct			s_des
{
	int				mode;
	const char		*args[6];
}						t_des;

enum					e_des_args
{
	i_arg,
	o_arg,
	k_arg,
	p_arg,
	s_arg,
	v_arg
};


typedef struct			s_flag
{
	unsigned short	num;
	unsigned char	group;
	unsigned char	ind;
	unsigned char	is_arg;
	unsigned char	arg_i;

}						t_flag;

static t_flag			g_flags[13] =
{
	{echo, md_group, 1, 0, 0},
	{quiet, md_group, 5, 0, 0},
	{reverse, md_group, 9, 0, 0},
	{string_sum, md_group, 13, 1, 0},
	{base, des_group, 0, 0, 0},
	{decode, base_group, 3, 0, 0},
	{encode, base_group, 4, 0, 0},
	{input, base_group, 8, 1, i_arg},
	{output, base_group, 14, 1, o_arg},
	{key, des_group, 10, 1, k_arg},
	{pass, des_group, 15, 1, p_arg},
	{salt, des_group, 18, 1, s_arg},
	{vector, des_group, 21, 1, v_arg}
};

int						show_usage(void *params);
int						show_command_error(void *params);
int						show_flag_error(void *params);
int						show_arg_error(void *params);
void					parse_md_flags(t_ssl *ssl);
void					parse_base_flags(t_ssl *ssl, const char **args);
void					parse_des_flags(t_ssl *ssl, const char **args);
void					process_stdin(t_ssl *ssl);
void					process_string(t_ssl *ssl);
void					process_file(t_ssl *ssl);
int						end_with_message(char *message, void *params, int ret);
int						get_group_ind(int cmd_ind);

void					set_read_buf_size(t_read *rd, t_common *alg);
int						read_block(t_read *rd, t_common alg);
int						uppend_block(t_read *rd, size_t i, t_common alg);
void					flip_bytes(unsigned char *byte, int len);

int						ft_md5(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha224(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha256(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha384(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha512(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha512_224(char const *message, t_prc_file *prc, \
	int print, char **digest);
int						ft_sha512_256(char const *message, t_prc_file *prc, \
	int print, char **digest);

int						ft_base64(t_ssl *ssl);
int						ft_des(t_ssl *ssl);
int						ft_des_ecb(t_ssl *ssl);
int						ft_des_cbc(t_ssl *ssl);

static t_end_wmsg		g_end_with_message[4] =
{
	&show_usage,
	&show_command_error,
	&show_flag_error,
	&show_arg_error
};

static t_get_hash		g_get_hash[7] =
{
	&ft_md5,
	&ft_sha224,
	&ft_sha256,
	&ft_sha384,
	&ft_sha512,
	&ft_sha512_224,
	&ft_sha512_256
};

static t_get_ssl		g_get_ssl[4] =
{
	&ft_base64,
	&ft_des,
	&ft_des_ecb,
	&ft_des_cbc
};

#endif
