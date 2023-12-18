/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:31:00 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/29 09:29:19 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_in_set(int c, char const *set)
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

int	check_percent_convert(int c, va_list args)
{
	int	i;

	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		i = convert_ptr(va_arg(args, unsigned long), "0123456789abcdef", 0);
	if (c == 'd')
		i = ft_putnbr(va_arg(args, int));
	if (c == 'i')
		i = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		i = convert_base(va_arg(args, unsigned int), "0123456789", 0);
	if (c == 'x')
		i = convert_base(va_arg(args, unsigned int), "0123456789abcdef", 0);
	if (c == 'X')
		i = convert_base(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	check_format(char *s, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && is_in_set(s[i + 1], "cspdiuxX%"))
		{
			len = len + check_percent_convert(s[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(arg_list, (char *)format);
	len = check_format((char *)format, arg_list);
	va_end(arg_list);
	return (len);
}
