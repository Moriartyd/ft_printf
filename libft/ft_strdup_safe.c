/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:50 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/07/21 02:22:58 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_safe(const char *s1)
{
	char	*s;
	size_t	i;

	i = -1;
	s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}
