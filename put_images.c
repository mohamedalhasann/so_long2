/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:39:54 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:54:35 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putimage(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, game->image.floor, j
		* TILE_SIZE, i * TILE_SIZE);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->image.wall, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->image.collect, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'P')
	{
		game->dimesnsion.x = i;
		game->dimesnsion.y = j;
	}
}
