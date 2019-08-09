/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:39:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/08/09 20:21:41 by cpollich         ###   ########.fr       */
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
	printf("|%d|", ft_printf("%f", 0.0 / 0.0));
	printf("\n");
	printf("|%d|", printf("%#f", -0.0 / 0.0));
	return (0);
}
