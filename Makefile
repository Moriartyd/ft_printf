# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 18:22:40 by cpollich          #+#    #+#              #
#    Updated: 2019/06/04 17:26:50 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
F = -Wall -Wextra -Werror

LIBFT = ./libft
SRC = ./src
INC = ./inc
OBJ = ./obj

SRCC	=	ft_printf.c\
			parser.c\
			print_char.c\
			print_dec.c\
			print_pointer\
			print_string.c\
			print_flags.c\
			print_num.c

OBJS = ($addprefix $(OBJ)/,$(SRC:%.c=%.o))
LIBFT_LIB = $(LIBFT)/libft.a
LIBFT_H = $(LIBFT)

all: $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(LIBFT_LIB):
	make -C libft

$(NAME): $(OBJ) $(LIBFT_LIB) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o
	ranlib $(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	gcc -g $F -c $< -I$(INC) -I$(LIBFT_H) -o $@

clean:
	rm -Rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -Rf $(NAME)
	make -C libft fclean

re: fclean all

norm:
	norminette
