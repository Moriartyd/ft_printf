/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:10:18 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/13 21:30:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

v_struct	*take_until_f(v_struct var, const char *form)
{
	int i;
	char *buf;
	ft_putstr(ft_copyuntil(form, "%"));

}