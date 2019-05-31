/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:37:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/31 14:44:41 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	vargs;
	int		i;
	int		ret;
	int		j;

	i = -1;
	va_start(vargs, form);
	while (form[++i])
	{
		if (form[i] == '%')
			ret += do_tok(form, vargs, &i);
		else
		{
			j += ft_putstr_until(form[i], '%');
			ret += j;
			i += j - 1;
		}
	}
	va_end(vargs);
	return (ret);
}
