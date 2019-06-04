/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:50 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/06/04 15:47:32 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_safe(const char *s1)
{
	char	*s;
	size_t	i;

	if (!s1)
		return (NULL);
	i = -1;
	s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}
