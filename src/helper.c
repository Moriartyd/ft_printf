/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:32:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/21 02:10:17 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_with_flag(char *str, int w, int p, char c)
{
	int	i;

	i = 0;
	if (p == -1)
	{
		i += ft_putstr(str);
		while (i < w)
			i += ft_putchar(c);
	}
	else
	{
		while (i < p && str[i])
			ft_putchar(str[i++]);
		while (i < w)
			i += ft_putchar(c);
	}
	return (i);
}

int		print_without_flag(char *str, int w, int p, char c)
{
	int	len;
	int	l;
	int	i;
	int j;

	len = ft_strlen(str);
	p == -1 ? (l = len) : (l = p);
	if (p != -1)
		l = (len > p) ? p : len;
	i = 0;
	while (w - i > l)
		i += ft_putchar(c);
	j = 0;
	while (str[j] && j < l)
		i = i + ft_putchar(str[j++]);
	return (i);
}

char	*gen_str(int size, int c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = (char*)ft_memset((void *)str, c, size);
	str[size] = '\0';
	return (str);
}

char	*ft_nchjoinstr(char *str, char c, int n)
{
	char	*res;
	int		i;
	int		j;

	if (n < 0)
		return (ft_strdup_safe(str));
	res = ft_strnew(ft_strlen(str) + n);
	j = -1;
	while (n--)
		res[++j] = c;
	i = -1;
	while (str[++i])
		res[++j] = str[i];
	return (res);
}

size_t	cast_to_flag(size_t n, t_token *tok)
{
	if ((tok->flags & F_HH) == F_HH)
		return ((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		return ((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		return ((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		return ((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		return ((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		return ((size_t)n);
	return ((unsigned int)n);
}
