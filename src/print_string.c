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

// static void     add_precision(t_token *token, char **string)
// {
//     char *new;

//     if (ft_strlen(*string) > token->precision && )
//     {
//         new = ft_strnew(token->precision);
//         ft_strncopy(new, *string, token->precision);
//         free(*string);
//         new = *string;
//     }
// }

int	print_string(char *ap, t_token *token)
{
	token->flags = 0;
	if (ap == NULL)
	{
		ft_strdup_safe("(null)");
		return (0);
	}
	else
		ap = ft_strdup_safe(ap);
		//add_precision(token, &ap);
	return (0);
}
