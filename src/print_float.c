/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:57:39 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/07/24 20:39:09 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_float(double nbr, t_token *token)
{
	char	*str;

	token->precision == -1 ? token->precision = 6 : 0;
	str = ft_ftoa();
}
