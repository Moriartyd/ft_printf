/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:43:16 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/31 14:48:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pos(char *str, t_token *token)
{
	char	*sign;
	int		res;

	sign = 0;
	res = 0;
	if (token->flags & F_PLUS == F_PLUS)
		sign = '+';
	if (token->flags & F_SPACE == F_SPACE)
		sign = ' ';
	if ((token->flags & F_ZERO == F_ZERO) && (token->flags & F_MINUS))
	{

	}
	else
	{

	}
}

static int	print_neg(char *str, t_token *token)
{
	
}

static int	print_pos_prec(char *str, t_token *token)
{
	
}

static int	print_neg_prec(char *str, t_token *token)
{
	
}

int			print_num(char *str, t_token *token, int sign)
{
	if (sign && token->precision == -1)
		return (print_pos(str, token));
	if (sign && token->precision != -1)
		return (print_pos_prec(str, token));
	if (!sign && token->precision != -1)
		return (print_neg_prec(str, token));
	return (print_neg(str, token));
}