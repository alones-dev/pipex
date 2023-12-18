/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:40 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/08 12:55:32 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isalphaupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isalphaupper(c))
		c = c + 32;
	return (c);
}
