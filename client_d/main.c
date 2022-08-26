/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:45:42 by jpaterno          #+#    #+#             */
/*   Updated: 2022/05/06 17:56:34 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*						CLIENT*/

#include "../libft/libft.h"

int	ft_end(int pid);
int	ft_end_carac(int pid, int *asci);
int	ft_push95(char c, int *asci, int pid);

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	asci;

	if (argc != 3 || !argv[2][0])
		return (0);
	i = 0;
	asci = 0;
	pid = ft_atoi(argv[1]);
	while ((unsigned char)argv[2][i] && asci != (unsigned char)argv[2][i])
	{
		if (asci == 0 && ft_push95(argv[2][i], &asci, pid) == 0)
			return (0);
		if ((asci + 15) <= (unsigned char)argv[2][i] && kill(pid, 31) != -1)
			asci += 15;
		else if ((asci++ + 1) <= (unsigned char)argv[2][i] &&
										kill(pid, 30) == -1)
			return (0);
		usleep(80);
		if (asci == (unsigned char)argv[2][i])
			i = i + ft_end_carac(pid, &asci);
	}
	return (ft_end(pid));
}

int	ft_push95(char c, int *asci, int pid)
{
	if (c && c > 95 && kill(pid, 31) != -1)
		*asci = 95;
	else
		if (kill(pid, 30) == -1)
			return (0);
	usleep(80);
	return (1);
}

int	ft_end(int pid)
{
	int	asci;

	asci = 80;
	while (asci < 256)
	{
		kill(pid, 31);
		usleep(80);
		asci += 15;
	}
	return (0);
}

int	ft_end_carac(int pid, int *asci)
{
	*asci = 0;
	kill(pid, 30);
	usleep(80);
	kill(pid, 31);
	usleep(80);
	kill(pid, 30);
	usleep(80);
	kill(pid, 31);
	usleep(80);
	return (1);
}
