# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uhand <uhand@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:42:26 by uhand             #+#    #+#              #
#    Updated: 2020/11/19 15:06:11 by uhand            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = ft_printf.h
SRC = ft_printf.c lib_printf.c add_fnctns.c set_format.c apply_flags.c \
formats_c_s.c format_float.c formats_int.c pft_itoa.c pft_unsigned_itoa.c \
pft_float_itoa.c pft_float_itoa_2.c pft_float_itoa_3.c double_rep.c \
ft_sprintf.c ft_fdprintf.c

OBJ = $(SRC:.c=.o)
FLAGS = -m64 -Ofast -flto -march=native -funroll-loops -Wall -Wextra -Werror
LIBPATH = ../

all: $(OBJ)

%.o: %.c $(HEAD)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ)
