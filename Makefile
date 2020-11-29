# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uhand <uhand@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 15:36:27 by uhand             #+#    #+#              #
#    Updated: 2020/11/29 16:57:19 by uhand            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

HEAD = ./includes
SRCPATH = ./srcs
SRC = ft_ssl.c end_with_message.c process_args.c md5.c md5_fghi.c md5_alg.c \
sha.c sha_init.c sha256_alg.c sha256_funcs.c sha512_alg.c sha512_funcs.c \
sha_output.c md_read.c md_padding.c md_common.c

OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))
OBJPATH = ./objects

FLAGS = -g #-fsanitize=address #-Wall -Wextra -Werror
LIB = -L ./libft -lft
LIBPATH = ./libft

all: $(NAME)

$(NAME): $(OBJPATH) $(OBJ)
	@make -C $(LIBPATH)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -I $(HEAD) $(LIB)

$(OBJPATH):
	@mkdir -p $(OBJPATH)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBPATH) clean
	@/bin/rm -rf $(OBJPATH)

fclean: clean
	@make -C $(LIBPATH) fclean
	@/bin/rm -f $(NAME)

re: fclean all
