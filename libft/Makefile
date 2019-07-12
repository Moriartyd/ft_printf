# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:21:28 by cpollich          #+#    #+#              #
#    Updated: 2019/06/04 21:02:43 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	=	ft_memalloc.c ft_memset.c ft_bzero.c ft_isdigit.c\
		ft_putchar.c ft_putnbr.c ft_putstr.c ft_putstr_until.c\
		ft_strcpy.c ft_strdel.c ft_strdup_safe.c ft_strlen.c ft_strncpy.c\
		ft_strnew.c ft_itoa_base.c ft_strjoin.c ft_strcat.c ft_strjoin_leak.c\
		ft_itoa_ubase.c

OBJ = $(SRC:.c=.o)

F = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $F -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette