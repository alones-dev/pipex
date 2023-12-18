/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:29 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/09 12:39:16 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s2;

	if (!little[0])
		return ((char *)big);
	i = 0;
	len_s2 = ft_strlen(little);
	while (big[i] && (i + len_s2 - 1) < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
		{
			if (j == len_s2 - 1)
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (0);
}
