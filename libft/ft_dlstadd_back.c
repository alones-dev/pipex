/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:47:49 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/06 12:49:20 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_dlstlast(*lst);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
