#include "libft.h"

char	*ft_strjoin_leak(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
