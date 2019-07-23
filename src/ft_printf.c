/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:37:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/23 17:19:20 by cpollich         ###   ########.fr       */
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
	ret = 0;
	j = 0;
	va_start(vargs, form);
	while (form[++i])
	{
		if (form[i] == '%')
			ret += do_tok(form + i + 1, vargs, &i);
		else
		{
			j = 0;
			j += ft_putstr_until((char *)form + i, '%');
			ret += j;
			i += j - 1;
		}
	}
	va_end(vargs);
	return (ret);
}
