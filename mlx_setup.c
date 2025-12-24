/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:01:31 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:57:22 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		freemap(game->map);
		return (0);
	}
	return (1);
}

int	create_window(t_game *game)
{
	game->height = ft_2dstrlen(game->map);
	game->width = ft_strlen(game->map[0]) - 1;
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		freemap(game->map);
		return (0);
	}
	return (1);
}

void	destroy_images(t_game *game)
{
	if (game->image.wall)
		mlx_destroy_image(game->mlx, game->image.wall);
	if (game->image.collect)
		mlx_destroy_image(game->mlx, game->image.collect);
	if (game->image.exit)
		mlx_destroy_image(game->mlx, game->image.exit);
	if (game->image.floor)
		mlx_destroy_image(game->mlx, game->image.floor);
	if (game->image.player)
		mlx_destroy_image(game->mlx, game->image.player);
}

int	put_image(t_game *game)
{
	int	w;
	int	h;

	game->movescounter = 0;
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w,
			&h);
	game->image.collect = mlx_xpm_file_to_image(game->mlx, "images/collect.xpm",
			&w, &h);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w,
			&h);
	game->image.floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w,
			&h);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
			&w, &h);
	if (!game->image.player || !game->image.wall || !game->image.collect
		|| !game->image.floor || !game->image.exit)
	{
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		freemap(game->map);
		return (0);
	}
	return (1);
}

int	render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			putimage(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.player,
		game->dimesnsion.y * TILE_SIZE, game->dimesnsion.x * TILE_SIZE);
	return (1);
}
