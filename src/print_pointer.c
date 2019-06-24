/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:46:11 by cpollich          #+#    #+#             */
/*   Updated: 2019/06/04 20:54:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long int p, t_token *token)
{
	int		l;
	char	*tmp1;
	char	*tmp2;

	token->flags = token->flags | F_SHARP;
	if (token->precision == -1)
		l = 1;
	else if (token->precision == 0)
		l = 0;
	else
		l = token->precision;
	if (p == 0)
	{
		token->flags = token->flags & (~(F_PLUS | F_SPACE));
		token->precision = -1;
		tmp1 = ft_nchjoinstr("", '0', l);
		tmp2 = ft_strjoin_leak("0x", tmp1);
		free(tmp1);
		l = print_num(tmp2, token, 1);
		free(tmp2);
		return (l);
	}
	token->flags = token->flags | F_LL;
	return (0);
}
