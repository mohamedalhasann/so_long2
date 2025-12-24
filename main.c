/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:19:55 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:52:10 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (argument_error());
	if (!ispathvalid(argv[1]))
		return (invalidpath());
	game.map = get_map(argv[1]);
	if (!game.map)
		return (failedmap());
	if (!mapvalidation(argv[1], game.map, game))
		return (0);
	if (!init_mlx(&game))
		return (0);
	if (!create_window(&game))
		return (0);
	if (!put_image(&game))
		return (0);
	render(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
}
