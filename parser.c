/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moriartyd <moriartyd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:10:18 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/14 09:29:16 by moriartyd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_putstr_until(const char *str, int c)
{
	int i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != c)
		ft_putchar(str[i]);
	return (str + i);
}

int			check_for_percent(const char *form)
{
	if (*(++form) == '%')
	{
		ft_putstr("%%");
		return (1);
	}
	return (0);
}

v_struct *parse_token(const char *form)
{
	int i;

	i = 0;
}

v_struct	*take_until_f(const char *form)
{
	int i;
	char *buf;

	form = ft_putstr_until(form, '%');
}