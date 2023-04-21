/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:47:24 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 09:55:09 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_map(t_game *game)
{
	if (!game->setup.map_width || !game->setup.map_height)
		str_error("ERROR:\n Invalid Map Parsing");
	if (game->player.dir == '\0')
		str_error("ERROR:\n No Player Position Given!");
	validate_map_horizontal(game->setup.map,
	game->setup.map_width, game->setup.map_height);
	validate_map_vertical(game->setup.map,
	game->setup.map_width, game->setup.map_height);
}

void	validate_map_horizontal(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != ' ' && map[y][0] != WALL)
			str_error("ERROR:\n Map Not Surronded By Walls! (Left Side)");
		x = 1;
		while (x < width)
		{
			while (x < width && map[y][x] == ' ')
				x++;
			if (x == width)
				break ;
			if (map[y][x - 1] == ' ' && map[y][x] != WALL)
				str_error("ERROR:\n Map Not Surronded By Walls! (Left Side)");
			while (x < width && map[y][x] != ' ')
				x++;
			if (map[y][x - 1] != WALL)
				str_error("ERROR:\n Map Not Surronded By Walls! (Right Side)");
		}
		y++;
	}
}

void	validate_map_vertical(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != ' ' && map[0][x] != WALL)
			str_error("ERROR:\n Map Not Surronded By Walls! (Upper Side)");
		y = 1;
		while (y < height)
		{
			while (y < height && map[y][x] == ' ')
				y++;
			if (y == height)
				break ;
			if (map[y - 1][x] == ' ' && map[y][x] != WALL)
				str_error("ERROR:\n Map Not Surronded By Walls! (Upper Side)");
			while (y < height && map[y][x] != ' ')
				y++;
			if (map[y - 1][x] != WALL)
				str_error("ERROR:\n Map Not Surronded By Walls! (Bottom Side)");
		}
		x++;
	}
}
