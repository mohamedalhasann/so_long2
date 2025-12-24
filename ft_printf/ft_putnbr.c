/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:09:10 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/02 13:32:12 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	result[11];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n == 0)
		count += ft_putchar('0');
	else if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	while (n > 0)
	{
		result[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		count += ft_putchar(result[i]);
	return (count);
}
