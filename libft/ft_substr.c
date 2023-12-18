/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:39 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/07 11:23:10 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	unsigned int	total_size;
	char			*new;

	total_size = 0;
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	s = s + start;
	while (s[total_size] && len--)
		total_size++;
	new = malloc(sizeof(char) * (total_size + 1));
	if (!new)
		return (free(new), NULL);
	ft_strlcpy(new, s, total_size + 1);
	return (new);
}
