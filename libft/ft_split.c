/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:15 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/06 16:29:41 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tbl;

	j = 0;
	tbl = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tbl)
		return (free(tbl), NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (*s && i)
		{
			tbl[j] = ft_substr(s, 0, i);
			if (!tbl[j++])
				return (free(tbl[j]), NULL);
		}
		s = s + i;
	}
	tbl[j] = NULL;
	return (tbl);
}
