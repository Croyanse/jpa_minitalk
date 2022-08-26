/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:59:39 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/12 19:00:03 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wint(int nb)
{
	char	*str;
	int		i;

	str = ft_itoa(nb);
	ft_putstr(str);
	i = ft_strlen(str);
	free (str);
	return (i);
}
