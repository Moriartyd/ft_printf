



#include <stdio.h>
#include <stdlib.h>



int ft_num_len_base(int num, int base)
{
    int i;

    i = (num < 0) ? 2 : 1;
    while((num = num / base) != 0)
        i++;
    return(i);
}


char    *ft_itoa_base(int num, int base)
{
    long n;
    int i;
    char *str;
    int sign;

    sign = (num < 0) ? -1 : 1;
    i = ft_num_len_base(num, base);
    if (num < 0)
    {
        n = -(long)num;
    }
    else
        n = (long)num;
  
    if (!(str = malloc(i + 1)))
        return(NULL);
    str[i] = '\0';
    
    while (n % base)
    {
        str[i - 1] = (n % base >= 10) ? n % base + 55 : n % base + '0';
        n /= base;
        //printf("%c\n", str[i]);
        i--;
    }
    printf("%d\n", 1);
    if (sign == -1)
        str[0] = '-';
    return(str);
}

// int main(int ac, char **av)
// {
//     if (ac != 3)
//         return (0);
//     printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
//     return(0);
// }