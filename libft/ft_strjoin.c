/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:42:56 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:42:57 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str;

	if (!(s1) || !(s2))
		return (NULL);
	str = (char *)s1;
	if (*s1 == '\0')
		return (ft_strdup(s2));
	ptr = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (*str != '\0')
		*ptr++ = *str++;
	str = (char *)s2;
	while (*str != '\0')
		*ptr++ = *str++;
	*ptr = '\0';
	return (ptr - (ft_strlen(s1) + ft_strlen(s2)));
}
