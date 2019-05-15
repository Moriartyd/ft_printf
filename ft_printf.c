/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:37:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/15 19:05:03 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	vargs;
	int		i;
	int		ret;

	i = -1;
	va_start(vargs, form);
	while (form[++i])
	{
		if (form[i] == '%')
			ret += do_tok(form, vargs, &i);
		else
			i += ft_putstr_until(form[i], '%');
	}
	va_end(vargs);
	return (ret);
}
