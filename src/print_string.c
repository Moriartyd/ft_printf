/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:09:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/06/04 21:02:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *ap, t_token *token)
{
	int	w;
	int	p;

	w = token->width;
	p = token->precision;
	if (!ap)
	{
		return (((token->flags & F_MINUS) != F_MINUS) ?
				print_without_flag("(null)", w, p, ' ') :
				print_with_flag("(null)", w, p, ' '));
	}
	if ((token->flags & F_MINUS) != F_MINUS)
		return (print_with_flag(ap, w, p, ' '));
	else
		return (print_without_flag(ap, w, p, ' '));	
}
