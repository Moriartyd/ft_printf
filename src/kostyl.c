#include "ft_printf.h"

int check_for_kostyl(long double n)
{
    if (n == 1 / 0.0 || n == -1 / 0.0)
        return (1);
    if (n != n)
        return (1);
    return (0);
}

int kostyl(long double n, t_token *tok)
{
    if (n == 1.0 / 0.0)
        return (print_string("inf", tok));
    if (n == -1.0 / 0.0)
        return (print_string("-inf", tok));
    if (n != n)
        return (print_string("nan", tok));
    return (0);
}