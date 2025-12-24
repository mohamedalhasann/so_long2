/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:33 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:50:35 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	onesonsides(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < ft_2dstrlen(map))
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			len--;
		if (i == 0 || i == ft_2dstrlen(map) - 1)
		{
			j = 0;
			while (j < len)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validcounters(char **map, t_game game)
{
	int	i;
	int	j;

	i = 0;
	game.exitcounter = 0;
	game.playercounter = 0;
	game.collectcounter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				game.playercounter++;
			else if (map[i][j] == 'C')
				game.collectcounter++;
			else if (map[i][j] == 'E')
				game.exitcounter++;
			j++;
		}
		i++;
	}
	return (game.playercounter == 1 && game.collectcounter
		&& game.exitcounter == 1);
}

int	floodfillvalidation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	shapevalidation(char **map)
{
	int		i;
	size_t	ref;
	size_t	current;

	if (!map || !map[0])
		return (0);
	ref = ft_strlen(map[0]);
	if (ref > 0 && map[0][ref - 1] == '\n')
		ref--;
	i = 0;
	while (map[i])
	{
		current = ft_strlen(map[i]);
		if (current > 0 && map[i][current - 1] == '\n')
			current--;
		if (current != ref)
			return (0);
		i++;
	}
	return (1);
}

int	charactersvalidation(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (!map || !map[0])
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
				&& c != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
