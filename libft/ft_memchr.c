/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:01 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/09 13:42:18 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;
	unsigned char	srch;

	i = 0;
	mem = (unsigned char *)s;
	srch = (unsigned char)c;
	while (i < n)
	{
		if (mem[i] == srch)
			return ((void *)mem + i);
		i++;
	}
	return (0);
}
