/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:31 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/11 01:34:32 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	srch;

	i = ft_strlen(s);
	srch = (char)c;
	while (i >= 0)
	{
		if (s[i] == srch)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
