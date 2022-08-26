/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:01:26 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/12 19:01:45 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstr(char *str)
{
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
