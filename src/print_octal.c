#include "ft_printf.h"

int	print_octal(size_t n, t_token *token)
{
	int	res;

	token->flags = token->flags & (~F_PLUS);
	token->flags = token->flags & (~F_SPACE);
	return (res);
}