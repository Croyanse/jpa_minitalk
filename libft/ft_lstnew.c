/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:40:02 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/11 21:40:03 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lis;

	lis = (t_list *)malloc(sizeof(t_list));
	if (!lis)
		return (NULL);
	lis->content = content;
	lis->next = NULL;
	return (lis);
}
