/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:58 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/07 11:19:11 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	convert_base(unsigned int n, char *base, int i)
{
	unsigned int	len;

	len = ft_strlenn(base);
	if (n >= len)
	{
		i = convert_base(n / len, base, i + 1);
		convert_base(n % len, base, i);
	}
	if (n < len)
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	convert_ptr(unsigned long n, char *base, int i)
{
	unsigned int	len;

	len = ft_strlenn(base);
	if (i == 0 && !n)
	{
		i = ft_putstr("(nil)");
		return (i);
	}
	if (i == 0)
		i = ft_putstr("0x");
	if (n >= len)
	{
		i = convert_ptr(n / len, base, i + 1);
		convert_ptr(n % len, base, i);
	}
	if (n < len)
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}
