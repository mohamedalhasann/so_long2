/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:54:14 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/22 19:43:08 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argument_error(void)
{
	ft_printf("Error\nno arguments passed");
	return (0);
}

int	invalidpath(void)
{
	ft_printf("Error\ninvalid path");
	return (0);
}

int	failedmap(void)
{
	ft_printf("Error\nfailed to read map");
	return (0);
}
