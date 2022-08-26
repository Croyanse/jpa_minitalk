/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:24:24 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/01 19:24:28 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	*iis_ns(char c, char *str, int choice, char *s)
{
	int		i;

	if (choice == 0)
	{
		while (*str)
		{
			if (*str == c)
				return ("true");
			str++;
		}
		return (NULL);
	}
	str = NULL;
	i = 0;
	while (s[i++] != '\n')
		;
	if (s[i] != '\0')
		str = ft_strdup(&s[i]);
	free (s);
	return (str);
}

char	*nlinsave(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\n')
		i++;
	if (i == 0)
		i = 1;
	str = malloc ((i + 2) * sizeof(char));
	if (!str)
	{
		free (s);
		return (NULL);
	}
	i = 0;
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = s[i];
	str[i + 1] = '\0';
	return (str);
}

int	create_save(char *buff, int fd, char **save)
{
	int	i;
	int	ix;

	ix = 0;
	i = 0;
	while (buff[i++] != '\n')
		;
	if (buff[i])
	{
		save[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!save[fd])
			return (0);
	}
	while (buff[i] && save[fd])
		save[fd][ix++] = buff[i++];
	buff[i - ix] = '\0';
	return (1);
}

char	*ft_gnl(int fd, char *str, char **save, char *buff)
{
	while (!(iis_ns('\n', str, 0, NULL)))
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			free (str);
		if (read(fd, buff, BUFFER_SIZE) <= 0)
		{
			free(buff);
			if (*str)
				return (str);
			return (NULL);
		}
		if (iis_ns('\n', buff, 0, NULL))
			if (create_save(buff, fd, save) == 0)
				free (str);
		str = ft_strjoinfree(str, buff);
		free (buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*save[OPEN_MAX];
	char		*buff;

	buff = NULL;
	str = "";
	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	if (save[fd])
	{
		if (iis_ns('\n', save[fd], 0, NULL))
		{
			str = nlinsave(save[fd]);
			save[fd] = iis_ns('.', ".", 1, save[fd]);
			return (str);
		}
		str = ft_strjoinfree(save[fd], str);
		save[fd] = NULL;
	}
	return (ft_gnl(fd, str, save, buff));
}
