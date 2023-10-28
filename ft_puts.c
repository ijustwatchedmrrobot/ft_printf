/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:15:10 by sozdamar          #+#    #+#             */
/*   Updated: 2023/10/28 15:15:11 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (*(s+ i))
	{
		write (1, &*(s + i), 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		i++;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_puthex(unsigned long a, char *s)
{
	
}