/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:50:01 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/21 13:50:02 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*ptr;
	char	*str;

	if (!s2 || !s1)
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
	ptr = ptr - (ft_strlen(s1) + ft_strlen(s2));
	free(s1);
	return (ptr);
}
