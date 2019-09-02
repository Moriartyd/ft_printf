#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int main()
{
	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	//printf("%%f Lydie == |%f|", (double)'L'+'y'+'d'+'i'+'e');
	return (0);
}

