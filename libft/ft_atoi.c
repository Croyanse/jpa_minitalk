/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:35:39 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:35:45 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strnum(const char *str)
{
	int	count;

	count = 0;
	while ((*str <= 57 && *str >= 48) || *str == 45 || *str == 43)
	{
		count++;
		str++;
	}
	return (count);
}

static bool	is_in_string2(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

static int	toolong(const char *c)
{
	if (*c == '-')
		return (0);
	return (-1);
}

static bool	is_space(char c)
{
	return (is_in_string2(c, "\t\n\v\f\r "));
}

int	ft_atoi(char *str)
{
	long long	result;
	long long	minus;

	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	if (ft_strnum(str) >= 19)
		return (toolong(str));
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * minus);
}
