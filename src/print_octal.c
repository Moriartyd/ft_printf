#include "ft_printf.h"

static size_t	cast_to_flag(size_t n, t_token *tok)
{
	if ((tok->flags & F_HH) == F_HH)
		return ((unsigned char)n);
	else if ((tok->flags & F_H) == F_H)
		return ((unsigned short)n);
	else if ((tok->flags & F_L) == F_L)
		return ((unsigned long)n);
	else if ((tok->flags & F_LL) == F_LL)
		return ((unsigned long long)n);
	else if ((tok->flags & F_J) == F_J)
		return ((intmax_t)n);
	else if ((tok->flags & F_Z) == F_Z)
		return ((size_t)n);
	return ((unsigned int)n);
}

int	print_octal(size_t n, t_token *token)
{
	int		res;
	char	*str;

	token->flags = token->flags & (~F_PLUS);
	token->flags = token->flags & (~F_SPACE);
	if (!(str = ft_itoa_ubase(cast_to_flag(n, token), 8)))
		return (0);
	if ((token->flags & F_SHARP) == F_SHARP)
	{
		token->precision =((n == 0 && token->precision == 0) ? -1 : 0);
		if (!n)
			res = print_num(str, token, 1);
		else
		{
			str = ft_strjoin_leak("0", str);
			res = print_num(str, token, 1);
		}
	}
	else
		res = print_num(str, token, 1);
	ft_strdel(&str);
	return (res);
}