/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:38:00 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/03 20:39:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int	main(void)
{
	ft_printf("%Lf", 21321321323123123.421421421l);
	printf("%Lf", 21321321323123123.421421421l);
	return (0);
}
