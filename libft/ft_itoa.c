/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:47:26 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/11 03:30:18 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	get_len_int(int nb)
{
	size_t	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_writenbr(long nb, char *str, int *i)
{
	if (nb <= 9)
		str[(*i)++] = nb + '0';
	else
	{
		ft_writenbr(nb / 10, str, i);
		ft_writenbr(nb % 10, str, i);
	}
}

char	*ft_itoa(int n)
{
	char	*final;
	int		i;
	long	n2;

	n2 = n;
	if (n2 == -2147483648)
		return (ft_strdup("-2147483648"));
	final = malloc(sizeof(char) * (get_len_int(n2) + 1));
	if (!final)
		return ((char *)0);
	i = 0;
	if (n2 < 0)
	{
		final[i++] = '-';
		n2 *= -1;
	}
	ft_writenbr(n2, final, &i);
	final[i] = '\0';
	return (final);
}
