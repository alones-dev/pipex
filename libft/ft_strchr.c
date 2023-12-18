/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:17 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/09 13:56:13 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	srch;

	i = 0;
	srch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == srch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == srch)
		return ((char *)s + i);
	return (0);
}
