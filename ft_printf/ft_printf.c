/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:02:30 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/07 14:36:30 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typecheck1(const char *s, va_list ap)
{
	int	count;

	count = 0;
	if ((*(s + 1) == 'd' || *(s + 1) == 'i'))
		count += ft_putnbr(va_arg(ap, int));
	else if (*(s + 1) == 'u')
		count += ft_putuns(va_arg(ap, unsigned int));
	else if (*(s + 1) == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int));
	else if (*(s + 1) == 'X')
		count += ft_putuhexa(va_arg(ap, unsigned int));
	else if (*(s + 1) == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*(s + 1) == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*(s + 1) == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (*(s + 1) == '%')
		count += ft_putchar(*s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	count;
	va_list			ap;

	va_start(ap, s);
	count = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			count += typecheck1(s, ap);
			s += 2;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(ap);
	return (count);
}

//  int	main(void)
//  {
//  	//int	num;
//  	//void *ptr;

// 	//num = 3;
//  	//ptr =&num;
//  	//printf("hexa: %x\n", -265);
//  		ft_printf("%%\n");

//  	return (0);
//  }
