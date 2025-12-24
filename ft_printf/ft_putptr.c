/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:33:56 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/02 21:29:30 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_puthexa(n) + 2);
}

// int main(void)
// {
//     void    *ptr;

//     ft_putptr(ptr,'X');
// 		printf("\n");
// 		printf("%p", ptr);
// }