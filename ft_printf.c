/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:01:31 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/28 15:01:33 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_hex(va_arg(arg, unsigned int), c);
	else if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_hex(va_arg(arg, unsigned int), 'x');
	}
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			len += ft_percent(args, *(str + 1));
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
