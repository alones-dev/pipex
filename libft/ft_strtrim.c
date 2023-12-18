/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:33 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/11 03:21:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, int c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(set, s1[start]))
		start++;
	while (is_in_set(set, s1[end - 1]) && end > start)
		end--;
	new = malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
