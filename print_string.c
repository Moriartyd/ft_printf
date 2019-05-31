/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:09:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/05/31 16:53:22 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     add_precision(t_token *token, char **string)
{
    char *new;

    if (ft_strlen(*string) > token->precision && )
    {
        new = ft_strnew(token->precision);
        ft_strncopy(new, *string, token->precision);
        free(*string);
        new = *string;
    }
}
char    print_s(char ap, t_token *token)
{    
    if (ap == NULL)
        return (ft_strdup("(null)"));
    else
        ap = ft_strdup(ap);
        add_precision(token, &ap);
    return (ap);
}