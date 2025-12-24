/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:26 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 15:51:55 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TILE_SIZE 50

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_images
{
	void		*wall;
	void		*floor;
	void		*collect;
	void		*exit;
	void		*player;
}				t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	int			movescounter;
	int			collectcounter;
	int			playercounter;
	int			exitcounter;
	t_point		dimesnsion;
	t_images	image;
}				t_game;
char			**get_map(char *argv);
int				countlines(char *path);
int				ft_2dstrlen(char **map);
void			findplayer(char **map, t_point *p);
void			floodfill(char **map, int x, int y);
char			**copy_map(char **map, char *argv);
char			**freemapwithclosingfd(char **map, int fd);
char			**freemap(char **map);
char			**closefd(int fd);
int				argument_error(void);
int				invalidpath(void);
int				onesonsides(char **map);
int				validcounters(char **map, t_game game);
int				shapevalidation(char **map);
int				charactersvalidation(char **map);
int				floodfillvalidation(char **map);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			print2d(char **arr);
int				ispathvalid(char *input);
int				mapvalidation(char *argv, char **map, t_game game);
int				init_mlx(t_game *game);
int				create_window(t_game *game);
int				get_map_width(char **map);
int				put_image(t_game *game);
int				render(t_game *game);
int				x_button(t_game *game);
int				other_keys(int key, t_game *game);
void			set_hooks(t_game *game);
int				failedmap(void);
void			destroy_images(t_game *game);
void			putimage(t_game *game, int i, int j);
