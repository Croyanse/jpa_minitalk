/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:58:04 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/12 18:59:00 by jpaterno         ###   ########.fr       */
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

int	ft_whex(unsigned int nb, char *base)
{
	int		len;
	char	*str;

	len = ft_dclen(nb);
	if (!len)
	{
		write(1, "0", 1);
		return (1);
	}
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
