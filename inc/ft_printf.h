/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:46:40 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/20 20:46:48 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include <string.h>
# include "libft.h"

/*
** Defining speces
*/

# define S_CHAR 'c'
# define S_STRING 's'
# define S_POINTER 'p'
# define S_PERCENT '%'
# define S_DECIMAL 'd'
# define S_INTEGER 'i'
# define S_OCTAL 'o'
# define S_HEX 'x'
# define S_BHEX 'X'
# define S_UNSIGNED 'u'
# define S_UNSIGNEDL 'U'
# define S_FLOAT 'f'

/*
** defining format flags
*/

# define F_MINUS (1 << 0)
# define F_ZERO (1 << 1)
# define F_PLUS (1 << 2)
# define F_SHARP (1 << 3)
# define F_SPACE (1 << 4)

/*
** defining length flags
*/

# define F_HH (1 << 5)
# define F_H (1 << 6)
# define F_L (1 << 7)
# define F_LL (1 << 8)
# define F_J (1 << 9)
# define F_Z (1 << 10)
# define F_BL (1 << 11)

typedef struct	s_token
{
	char		spec;
	char		width;
	char		precision;
	int			flags;
}				t_token;

int				ft_printf(const char *form, ...);
int				do_tok(const char *form, va_list vargs, int *i);
int				print_num(char *str, t_token *token, int sign);

/*
**	PRINT
*/

int				print_dec(long long int n, t_token *token);
int				print_pointer(unsigned long long int p, t_token *token);
int				print_char(char c, t_token *token);
int				print_string(char *ap, t_token *token);
int				print_octal(size_t n, t_token *token);
int				print_hex(size_t n, t_token *token);

/*
**	Helper funcs
*/

char			*gen_str(int size, int c);
int				print_without_flag(char *str, int w, int p, char c);
int				print_with_flag(char *str, int w, int p, char c);
char			*ft_nchjoinstr(char *str, char c, int n);
size_t			cast_to_flag(size_t n, t_token *tok);

#endif
