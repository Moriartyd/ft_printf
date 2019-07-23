#include "ft_printf.h"

int	main()
{
	printf("|%d|",ft_printf("%#.3o", 1));
	printf("\n");
	printf("|%d|", printf("%#.3o", 1));
	return (0);
}