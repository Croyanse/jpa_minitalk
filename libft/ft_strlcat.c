/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:43:16 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:43:17 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_str_length_fast(const char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*dst1;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaing;

	dst1 = dst;
	src_start = (char *)src;
	remaing = dstsize;
	while (remaing-- != 0 && *dst1 != '\0')
		dst1++;
	dst_length = dst1 - dst;
	remaing = dstsize - dst_length;
	if (remaing == 0)
		return (dst_length + ft_str_length_fast(src));
	while (*src != '\0')
	{
		if (remaing > 1)
		{
			*dst1++ = *src;
			remaing--;
		}
		src++;
	}
	*dst1 = '\0';
	return (dst_length + (src - src_start));
}
