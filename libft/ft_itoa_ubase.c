#include "libft.h"

static int	ft_num_len_base(int num, int base)
{
	int i;

	i = 1;
	while ((num = num / base) != 0)
		i++;
	return (i);
}

char		*ft_itoa_ubase(size_t num, int base)
{
	size_t	n;
	int		i;
	char	*str;

	i = ft_num_len_base(num, base);
	n = num;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (n)
	{
		str[i - 1] = (n % base >= 10) ? n % base + 55 : n % base + '0';
		n /= base;
		i--;
	}
	return (str);
}