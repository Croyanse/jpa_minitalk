/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:45:50 by jpaterno          #+#    #+#             */
/*   Updated: 2022/05/04 18:45:51 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*								SERVER*/

#include "../libft/libft.h"

t_creabin	g_b;
void	ft_free(void);

void	ft_resize_and_refresh(int choice)
{
	unsigned char	*new_alloc;

	if (choice == 1)
	{
		g_b.pos = 0;
		g_b.sizealloc = 50;
		g_b.ctrl = 0;
		free(g_b.len_c);
		g_b.len_c = ft_calloc(g_b.sizealloc, 1);
		if (g_b.len_c == NULL)
			ft_free ();
		return ;
	}
	g_b.sizealloc = g_b.sizealloc * 2;
	new_alloc = ft_calloc((g_b.sizealloc), 4);
	if (new_alloc == NULL)
		ft_free ();
	ft_memcpy(new_alloc, g_b.len_c, g_b.sizealloc / 2);
	free(g_b.len_c);
	g_b.len_c = new_alloc;
	g_b.ctrl = 0;
}

int	ft_hckend(int nb)
{
	if (nb != 0)
	{
		g_b.h[3] = g_b.h[2];
		g_b.h[2] = g_b.h[1];
		g_b.h[1] = g_b.h[0];
		g_b.h[0] = nb;
	}
	if (g_b.h[0] == 15 && g_b.h[1] == 1 && g_b.h[2] == 15 && g_b.h[3] == 1)
	{
		g_b.h[0] = 0;
		g_b.len_c[g_b.pos] = g_b.len_c[g_b.pos] - 32 ;
		g_b.ctrl = 0;
		g_b.pos++;
		if (g_b.pos >= g_b.sizealloc)
			ft_resize_and_refresh(0);
		return (1);
	}
	return (0);
}

void	ft_bin1(int x)
{
	x = 0;
	if (g_b.ctrl == 0)
	{
		g_b.ctrl = 1;
		return ;
	}
	g_b.len_c[g_b.pos] = g_b.len_c[g_b.pos] + 1;
	ft_hckend(1);
}

void	ft_bin15(int x)
{
	x = 0;
	if (g_b.ctrl == 0)
	{
		g_b.ctrl = 1;
		g_b.len_c[g_b.pos] = 95;
		return ;
	}
	if ((g_b.len_c[g_b.pos]) + 15 > 256)
	{
		g_b.len_c[g_b.pos] = 0;
		ft_printf("%s\n", g_b.len_c);
		ft_resize_and_refresh(1);
		return ;
	}
	g_b.len_c[g_b.pos] += 15;
	ft_hckend(15);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid = %d\n", pid);
	g_b.sizealloc = 50;
	g_b.len_c = ft_calloc(g_b.sizealloc, 1);
	if (g_b.len_c == NULL)
		return (0);
	g_b.pos = 0;
	g_b.h = malloc(4 * sizeof(int));
	if (g_b.h == NULL)
		return (0);
	g_b.ctrl = 0;
	signal(SIGUSR1, ft_bin1);
	signal(SIGUSR2, ft_bin15);
	while (1)
	{
		pause();
	}
}
