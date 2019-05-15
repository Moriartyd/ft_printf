/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:10:18 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/15 20:07:11 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_until(const char *str, int c)
{
	int i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != c)
		;
	write(1, str, i);
	return (i);
}

int		begin_flag(int c)
{
	if (c == '-')
		return (F_MINUS);
	if (c == '0')
		return (F_ZERO);
	if (c == '+')
		return (F_PLUS);
	if (c == '#')
		return (F_SHARP);
	if (c == ' ')
		return (F_SPACE);
	return (0);
}

int		length_flag(const char *f, int *i)
{
	if ((f[*i] == 'h' && f[*i + 1] == 'h')
		|| (f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		*i += 2;
		return (f[*i] == 'h' ? F_HH : F_LL);
	}
	else if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z' ||
		f[*i] == 'L')
	{
		*i++;
		if (f[*i - 1] == 'h')
			return (F_H);
		if (f[*i - 1] == 'l')
			return (F_L);
		if (f[*i - 1] == 'j')
			return (F_J);
		if (f[*i - 1] == 'z')
			return (F_Z);
		if (f[*i - 1] == 'L')
			return (F_BL);
	}
	return (0);
}

int		parse_tok(const char *form, t_token token)
{
	int	i;
	int	flag;

	i = 0;
	while (form[i] && (flag = begin_flag(form[i++])))
		token.flags = token.flags | flag;
	while (form[i] && ft_isdigit(form[i]))
		token.width = token.width * 10 + form[i++] - '0';
	if (form[i] == '.')
		while (form[++i] && ft_isdigit(form[i]))
			if (token.prescision == -1)
				token.prescision = form[i] - '0';
			else
				token.prescision = token.prescision * 10 + form[i] - '0';
	if (form[i - 1] == '.' && token.prescision == -1)
		token.prescision = 0;
	if ((flag = length_flag(form, &i)))
		token.flags = token.flags | flag;
	token.spec = form[i];
	return (i);
}

int		do_tok(const char *form, va_list vargs, int *i)
{
	t_token token;

	token.width = 0;
	token.prescision = -1;
	token.flags = 0;
	parse_tok(form, token);
}