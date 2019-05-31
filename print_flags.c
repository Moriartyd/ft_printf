/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:32:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/31 21:33:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_with_flag(char *str, int w, int p, char c)
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

int	print_without_flag(char *str, int w, int p, char c)
{
	int	len;
	int	l;
	int	i;
	int j;

	len = ft_strlen(str);
	l = (p == -1) ? len : p;
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
