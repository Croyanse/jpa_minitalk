/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:00:33 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/12 19:01:08 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_dclen(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_hexo(unsigned long nb, char *base)
{
	int		len;
	char	*str;

	len = ft_dclen(nb);
	if (!len)
		write(1, "0", 1);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (nb && len)
	{
		str[--len] = base[nb % 16];
		nb /= 16;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_wptr(void *ptr)
{
	unsigned long	test;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	test = (long long)ptr;
	write(1, "0x", 2);
	return (ft_hexo(test, "0123456789abcdef") + 2);
}
