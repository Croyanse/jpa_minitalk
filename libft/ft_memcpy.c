/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:40:41 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:40:42 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	void	*target;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = dst;
	s = (void *)src;
	target = (void *)dst;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (target);
}
