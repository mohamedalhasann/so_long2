/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:34:34 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:51:13 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countlines(char *path)
{
	int		fd;
	char	*buffer;
	int		counter;

	fd = open(path, O_RDONLY);
	counter = 0;
	if (fd < 0)
		return (-1);
	buffer = get_next_line(fd);
	while (1)
	{
		if (!buffer)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (counter);
}

char	**get_map(char *argv)
{
	int		i;
	int		fd;
	char	**map;
	int		lines;

	lines = countlines(argv);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (freemap(map));
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (freemapwithclosingfd(map, fd));
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	findplayer(char **map, t_point *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p->x = i;
				p->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	floodfill(char **map, int x, int y)
{
	if (!map || x < 0 || y < 0 || !map[x] || !map[x][y])
		return ;
	if (map[x][y] == '1' || map[x][y] == 'M')
		return ;
	map[x][y] = 'M';
	floodfill(map, x - 1, y);
	floodfill(map, x + 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int	mapvalidation(char *argv, char **map, t_game game)
{
	char	**temp;
	t_point	p;

	if (!onesonsides(map) || !validcounters(map, game) || !shapevalidation(map)
		|| !charactersvalidation(map))
	{
		ft_printf("Error\ninvalid map");
		freemap(map);
		return (0);
	}
	findplayer(map, &p);
	temp = get_map(argv);
	floodfill(temp, p.x, p.y);
	if (!floodfillvalidation(temp))
	{
		freemap(temp);
		freemap(map);
		ft_printf("Error\nflood fill error");
		return (0);
	}
	freemap(temp);
	return (1);
}
