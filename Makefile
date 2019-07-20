# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 18:22:40 by cpollich          #+#    #+#              #
#    Updated: 2019/07/21 01:58:26 by cpollich         ###   ########.fr        #
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
			print_octal.c\
			print_hex.c\
			print_pointer.c\
			print_string.c\
			helper.c\
			print_num.c

OBJS = $(addprefix $(OBJ)/,$(SRCC:%.c=%.o))
LIBFT_LIB = $(LIBFT)/libft.a
LIBFT_H = $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o
	ranlib $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(LIBFT_LIB):
	make -C libft

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

test:
	@@gcc main.c src/*.c libft/*.c -o libftprintf.a -I./inc -I./libft
	@@./libftprintf.a