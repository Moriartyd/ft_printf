#include "ft_printf.h"

int	main()
{
	printf("|%d|", ft_printf("before %X after", 42));
	printf("\n");
	printf("|%d|", printf("before %X after", 42));
	return (0);
}