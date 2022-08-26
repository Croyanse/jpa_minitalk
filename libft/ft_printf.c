/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:05:23 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/11 16:05:26 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tri(char choice, va_list strin)
{
	if (choice == 'd' || choice == 'i')
		return (ft_wint(va_arg(strin, int)));
	else if (choice == 'c')
		return (ft_wchar(va_arg(strin, int)));
	else if (choice == 's')
		return (ft_wstr(va_arg(strin, char *)));
	else if (choice == 'p')
		return (ft_wptr(va_arg(strin, void *)));
	else if (choice == 'u')
		return (ft_wuint(va_arg(strin, int)));
	else if (choice == 'x')
		return (ft_whex(va_arg(strin, int), "0123456789abcdef"));
	else if (choice == 'X')
		return (ft_whex(va_arg(strin, int), "0123456789ABCDEF"));
	else if (choice == '%')
		return (ft_wchar('%'));
	return (0);
}

int	ft_printf(const char *strin, ...)
{
	va_list	ap;
	int		i;
	int		buff;

	buff = 0;
	i = 0;
	va_start (ap, strin);
	while (strin[i])
	{
		if (strin[i] == '%' && strin[i + 1] != '\0')
		{
			i++;
			buff += ft_tri(strin[i], ap);
			buff -= 2;
			i++;
		}
		else
		{
			write(1, &strin[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (i + buff);
}
/*
int	main()
{
	const char *str = "yolo";
	char *ptr = "test1";
	int a = ft_printf("MINE = %u\n", -10);
	int b = printf("REAL = %u\n", -10);
	printf("%d %d", a, b);
}*/
