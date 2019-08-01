/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:52:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/01 17:18:04 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bignum		*bin_mult(t_bignum *l)
{
	t_bignum	*res;
	t_string	new_frac_part;

	res = big_num_create();
	res->sign = l->sign;
	new_frac_part = str_cut(&l->frac_part, 1, str_len(&l->frac_part));
	str_push_cs(&res->frac_part, &new_frac_part);
	str_push_cs(&res->int_part, &l->int_part);
	str_pushchar(&res->int_part, str_at(&l->frac_part, 0));
	if (str_len(&res->int_part) == 0)
		str_pushchar(&res->int_part, '0');
	if (str_len(&res->frac_part) == 0)
		str_pushchar(&res->frac_part, '0');
	str_destroy(&new_frac_part);
	return (res);
}

t_bignum		*bin_div(t_bignum *l)
{
	t_bignum	*res;
	t_string	tmp;

	res = big_num_create();
	res->sign = l->sign;
	tmp = str_cut(&l->int_part, 0, str_len(&l->int_part) - 1);
	str_push_cs(&res->int_part, &tmp);
	str_pushchar(&res->frac_part,
				str_at(&l->int_part, str_len(&l->int_part) - 1));
	str_push_cs(&res->frac_part, &l->frac_part);
	if (str_len(&res->int_part) == 0)
		str_pushchar(&res->int_part, '0');
	if (str_len(&res->frac_part) == 0)
		str_pushchar(&res->frac_part, '0');
	return (res);
}

void			str_destroy(t_string *s)
{
	free(s->data);
	s->data = NULL;
	s->capacity = 0;
	s->size = 0;
}

void			big_num_destroy(t_bignum **num)
{
	str_destroy(&(*num)->int_part);
	str_destroy(&(*num)->frac_part);
	free(*num);
	*num = NULL;
}

void			pos_pow(t_bignum **n, int power, t_bignum *(*f)(t_bignum *))
{
	t_bignum	*tmp;
	int			i;

	i = -1;
	while (++i < ft_abs(power))
	{
		tmp = (*f)(*n);
		big_num_destroy(n);
		*n = tmp;
	}
}