/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:47:49 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/06 12:49:38 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*temp;

	temp = *lst;
	new->next = temp;
	new->prev = NULL;
	if (temp)
		temp->prev = new;
	*lst = new;
}
