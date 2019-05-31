/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:09:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/05/24 21:17:19 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     add_precision(t_token *token, char **string)
{
    char *new;

    if (ft_strlen(*string) > token->prescision)
    {
        new = ft_strnew(token->prescision);
        ft_strncopy(new, *string, token->prescision);
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