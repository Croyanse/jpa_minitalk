/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:09:31 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:40:24 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	c = c % 256;
	ptr = (char *)s;
	if (c > 270)
		c -= 256;
	while (n != 0)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
		n--;
	}
	if (n == 0)
	{
		ptr = NULL;
		return (ptr);
	}
	else
		return (ptr);
}
