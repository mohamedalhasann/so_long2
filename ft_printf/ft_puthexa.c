/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:35:15 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/02 21:20:13 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long num)
{
	char	*hex_digits;
	char	temp[17];
	int		i;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		temp[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		count += ft_putchar(temp[i]);
	return (count);
}
