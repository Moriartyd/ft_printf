/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:11:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/05/23 22:52:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(int n)
{
	int size;

	size = 0;
	if (n < 0)
		size++;
	while (n % 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int		dec_power(int size)
{
	int	res;

	res = 1;
	while (--size)
		res *= 10;
	return (res);
}

int	ft_putnbr(int n)
{
	char	*res;
	int		del;
	int		size;
	int		i;

	i = 0;
	size = ft_size(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	del = dec_power(size);
	res[size] = 0;
	while (n)
	{
		n /= del;
		res[i++] = n;
		del /= 10;
	}
	write(1, res, size);
	return (size);
}

// void	ft_putnbr(int n)
// {
// 	char	*res;

// 	if (n == -n)
// 	{
// 		ft_putchar('-');
// 		ft_putchar('2');
// 		ft_putnbr(147483648);
// 	}
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			ft_putchar('-');
// 			n *= -1;
// 		}
// 		if (n >= 0 && n <= 9)
// 		{
// 			ft_putchar('0' + n);
// 		}
// 		else
// 		{
// 			ft_putnbr(n / 10);
// 			ft_putchar('0' + n % 10);
// 		}
// 	}
// }

int main(int ac, char **av)
{
    int n = atoi(av[1]);
    ft_putnbr(n);
    printf("\n%i", n);
}