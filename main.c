/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:39:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/01 17:36:46 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void *malloc(size_t size)
// {
// 	size = 0;
// 	return (NULL);
// }

int	main(void)
{
	int i = 32;
	void *p = &i;
	printf("|%d|", ft_printf("%f", 0/1));
	printf("\n");
	printf("|%d|", printf("%f", 0/0));
	return (0);
}
