/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:39:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/01 14:19:04 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void *malloc(size_t size)
{
	size = 0;
	return (NULL);
}

int	main(void)
{
	int i = 32;
	void *p = &i;
	printf("|%d|", ft_printf("%#X", i));
	printf("\n");
	printf("|%d|", printf("%#o", 23));
	return (0);
}
