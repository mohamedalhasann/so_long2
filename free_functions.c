/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:45:11 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/22 19:38:54 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**freemapwithclosingfd(char **map, int fd)
{
	freemap(map);
	close(fd);
	return (NULL);
}

char	**freemap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

char	**closefd(int fd)
{
	close(fd);
	return (NULL);
}
