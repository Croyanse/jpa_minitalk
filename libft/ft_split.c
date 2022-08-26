/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:42:07 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:42:08 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbwords(char *str, char c)
{
	int	count;

	count = 1;
	if (*str == c)
		count = 0;
	while (*str != '\0')
	{
		if (*str == c && *(str + 1) != c && *(str + 1) != '\0')
			count++;
		str++;
	}
	return (count);
}

static int	ft_strlensplit(char *str, char c)
{
	int	count;

	count = 0;
	if (*str == c)
		str++;
	while (*str != '\0' && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

static void	ft_memcpysplit(void *dest, void *p, size_t size, char c)
{
	char	*d;
	char	*s;
	char	*target;

	d = dest;
	target = d;
	s = p;
	if (*s == c)
		s++;
	while (size)
	{
		*d = *s;
		d++;
		s++;
		size--;
	}
	*d = '\0';
}

static char	*ft_igni_and_del(int *a, int *b, char **c, const char *s)
{
	int	i;

	i = 0;
	if (c != NULL)
	{
		*a = 0;
		*b = 0;
		return ((char *)s);
	}
	while (c)
	{
		free(c[i]);
		i++;
	}
	free(c);
	return (NULL);
}

////////////////////// WELCOME IN THE WORST SPLIT EVER LOL
///	k = used to force the first character

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*p;
	int		ptc;
	int		k;

	if (!(s))
		return (NULL);
	tab = malloc((ft_nbwords((char *)s, c) + 1) * sizeof(char *));
	if (!(tab))
		return (NULL);
	p = ft_igni_and_del(&ptc, &k, tab, s);
	while (*p != '\0')
	{
		if (((*p == c && *(p + 1) != c && *(p + 1))) || (k != 1 && *p != c))
		{
			tab[ptc] = malloc((ft_strlensplit(p, c) + 1) * sizeof(char));
			ft_memcpysplit(tab[ptc++], p, ft_strlensplit(p, c), c);
			if (!tab[ptc - 1])
				return ((char **)ft_igni_and_del(&ptc, &k, tab, s));
			k = 1 ;
		}
		p++;
	}
	tab[ptc] = NULL;
	return (tab);
}
/*
int	main()
{
	char **tab = ft_split("5d945263-1-2-3-4-5-6-7-8--8-8--8-4------4--4", '-');
	while(*tab)
	{
		printf("%s\n", *tab);
		tab ++;
	}
}*/
