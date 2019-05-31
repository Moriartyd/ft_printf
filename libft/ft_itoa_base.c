/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:45:45 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/31 14:47:08 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len_base(int num, int base)
{
	int i;

	i = (num < 0) ? 2 : 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}


char		*ft_itoa_base(int num, int base)
{
	long	n;
	int		i;
	char	*str;
	int		sign;

	sign = (num < 0) ? -1 : 1;
	i = ft_num_len_base(num, base);
	n = (num < 0 ? -(long)num : (long)num);
	if (num < 0)
		n = -(long)num;
	else
		n = (long)num;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return(NULL);
	str[i] = '\0';
	while (n % base)
	{
		str[i - 1] = (n % base >= 10) ? n % base + 55 : n % base + '0';
		n /= base;
		i--;
	}
	printf("%d\n", 1);
	if (sign == -1)
		str[0] = '-';
	return (str);
}

/*
**int main(int ac, char **av)
**{
**	if (ac != 3)
**		return (0);
**	printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
**	return(0);
**}
*/