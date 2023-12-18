/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:42 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/08 12:55:23 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isalphalower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_isalphalower(c))
		c = c - 32;
	return (c);
}
