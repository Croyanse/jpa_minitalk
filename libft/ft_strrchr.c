/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:44:19 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:44:20 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	c = c % 256;
	ptr = NULL;
	while (*s)
	{
		if (*s == c)
			ptr = ((char *)s);
		s++;
	}
	if (!(c))
		return ((char *)s);
	return (ptr);
}
