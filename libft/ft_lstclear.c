/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:03:40 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/11 03:27:25 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*act;
	t_list	*save;

	act = *lst;
	while (act)
	{
		save = act->next;
		ft_lstdelone(act, del);
		act = save;
	}
	*lst = NULL;
}
