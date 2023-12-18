/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:05 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/11 01:15:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*mem;
	char	*base;

	i = 0;
	mem = (char *)dest;
	base = (char *)src;
	while (i < n)
	{
		mem[i] = base[i];
		i++;
	}
	return ((void *)mem);
}
