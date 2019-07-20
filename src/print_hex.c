/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:12:16 by cpollich          #+#    #+#             */
/*   Updated: 2019/07/21 02:48:18 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_num_len_base(size_t num, int base)
{
	int i;

	i = 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}

static char		*ft_itoa_uhex(size_t num, char spec)
{
	char	*alpha;
	char	*res;
	int		len;

	alpha = "0123456789abcdef";
	if (spec == S_BHEX)
		alpha = "0123456789ABCDEF";
	if (num == 0)
		return (ft_strdup_safe("0"));
	len = ft_num_len_base(num, 16);
	res = ft_strnew(len--);
	while (num)
	{
		res[len--] = alpha[num % 16];
		num /= 16;
	}
	return (res);
}

static void		parsing(size_t num, t_token *token, char **str, int len)
{
	char	*tmp;

	if (token->precision > len)
	{
		tmp = ft_nchjoinstr(*str, '0', token->precision - len);
		free(*str);
		*str = tmp;
		token->flags = token->flags & (~F_ZERO);
	}
	if ((token->flags & F_ZERO) == F_ZERO && token->precision == -1
		&& num && (token->flags & F_MINUS) == F_MINUS)
	{
		tmp = ft_nchjoinstr(*str, '0', token->width - len -
			((token->flags & F_SHARP) == F_SHARP) * 2);
		free(*str);
		*str = tmp;
	}
	if ((token->flags & F_SHARP) == F_SHARP && num)
	{
		tmp = ft_strjoin_leak((token->spec == S_BHEX) ? "0X" : "0x", *str);
		free(*str);
		*str = tmp;
		token->flags = token->flags & (~F_ZERO);
	}
}

int				print_hex(size_t n, t_token *token)
{
	char	*str;
	int		res;

	token->flags = token->flags & (~F_PLUS & ~F_SPACE);
	if (!n && token->precision == 0)
		print_num("", token, 1);
	if (!(str = ft_itoa_uhex(n, token->spec)))
		return (0);
	parsing(n, token, &str, ft_strlen(str));
	token->precision = -1;
	res = print_num(str, token, 1);
	ft_strdel(&str);
	return (res);
}
