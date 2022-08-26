/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:42:28 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:42:29 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		count;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	dest = malloc(sizeof(char) * (size + 1));
	if (!(dest))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		dest[count] = (char)s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
