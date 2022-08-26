/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wuint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:02:28 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/12 19:03:16 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenght(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n / 10 != 0 && count++ < 10)
		n = n / 10;
	return (count);
}

int	ft_wuint(unsigned int n)
{
	int		len;
	char	*str;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_lenght(n) + 1;
	str = malloc((len + 1) * sizeof(char));
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		str[len--] = 48 + (n % 10);
		n = n / 10;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
