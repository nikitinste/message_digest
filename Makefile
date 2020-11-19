

NAME = ft_ssl

HEAD = ./includes
SRCPATH = ./srcs
SRC = ft_ssl.c end_with_message.c process_args.c md5.c md5_fghi.c sha256.c \
md5_alg.c

OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))
OBJPATH = ./objects

FLAGS =  -m64 -Ofast -flto -march=native -funroll-loops#-g -Wall -Wextra -Werror
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
