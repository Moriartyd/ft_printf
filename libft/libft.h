/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:32:08 by cpollich          #+#    #+#             */
/*   Updated: 2019/06/04 16:27:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
**	PUT block
*/

int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putstr_until(const char *str, int c);

/*
**	STR block
*/

char	*ft_strdup_safe(const char *s1);
size_t	ft_strlen(const char *str);
void	ft_strdel(char **as);
char	*ft_itoa_base(int num, int base);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcpy(char *dst, const char *src);

/*
**	MEMORY block
*/

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);

#	endif
