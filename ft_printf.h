/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:37:35 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/13 21:44:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/includes/libft.h"

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

# define F_MINUS (1 << 0)
# define F_ZERO (1 << 1)
# define F_PLUS (1 << 2)
# define F_SHARP (1 << 3)
# define F_SPACE (1 << 4)

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
	char		prescision;
	int			flags;
}				t_token;

#endif