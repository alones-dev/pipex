/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:47:49 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/06 12:51:00 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst->next)
	{
		ft_dlstadd_back(&new, ft_dlstnew(f(lst->content)));
		if (!ft_dlstlast(new))
		{
			ft_dlstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	ft_dlstadd_back(&new, ft_dlstnew(f(lst->content)));
	if (!ft_dlstlast(new))
	{
		ft_dlstclear(&new, del);
		return (NULL);
	}
	return (new);
}
