/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:53:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/09 20:45:02 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_resize(t_string *s, int new_size)
{
	char	*new_data;
	int		i;

	i = -1;
	new_data = ft_strnew(new_size - 1);
	while (++i < s->size)
		new_data[i] = s->data[i];
	free(s->data);
	s->data = new_data;
	s->capacity = new_size;
}

void		str_pushchar(t_string *s, char c)
{
	if (s->size == s->capacity)
		str_resize(s, s->size + 25);
	s->data[s->size] = c;
	s->size++;
}

char		str_at(t_string *s, int idx)
{
	return (s->data[idx]);
}

t_string	str_create_size(int size)
{
	t_string	str;

	str.data = ft_strnew(size - 1);
	str.size = 0;
	str.capacity = size;
	return (str);
}
