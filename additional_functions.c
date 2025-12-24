/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:25:36 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/24 13:32:29 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_2dstrlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ispathvalid(char *input)
{
	if (ft_strncmp(&input[ft_strlen(input) - 4], ".ber", 4))
		return (0);
	return (1);
}

void	print2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
}

int	get_map_width(char **map)
{
	int	width;

	width = ft_strlen(map[0]);
	if (width > 0 && map[0][width - 1] == '\n')
		width--;
	return (width);
}
