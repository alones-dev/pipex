/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:47:49 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/06 12:49:55 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst)->next)
	{
		temp = (*lst)->next;
		ft_dlstdelone(*lst, del);
		*lst = temp;
	}
	ft_dlstdelone(*lst, del);
	*lst = NULL;
}
