/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:32:02 by cpollich          #+#    #+#             */
/*   Updated: 2019/06/04 18:31:02 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_until(const char *str, int c)
{
	int i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] && str[i] != c)
		;
	write(1, str, i);
	return (i);
}
