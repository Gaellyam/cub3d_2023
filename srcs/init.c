/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:43:43 by glamy             #+#    #+#             */
/*   Updated: 2020/11/30 08:19:06 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_setup(t_game *game)
{
	int i;

	i = 0;
	while (i < PARAMS)
		game->setup.param[i++] = -1;
	game->setup.res_width = 0;
	game->setup.res_height = 0;
	ft_memset(game->setup.tex.path, 0, 6);
	game->setup.tex.floor = -1;
	game->setup.tex.ceiling = -1;
	game->setup.map = NULL;
	game->setup.map_width = 0;
	game->setup.map_height = 0;
	game->player.dir = '\0';
	game->sprite = NULL;
	game->num_sprite = 0;
	game->buf = NULL;
	game->n_buffer = NULL;
}

void	init_player(t_game *game, int i, int j)
{
	if (game->player.dir)
		str_error("ERROR:\n Multiple Player Postions Given!");
	game->player.dir = game->setup.map[i][j];
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->player.move_speed = 0.2;
	game->player.rot_speed = 0.08;
	game->player.posx = 0.5f + j;
	game->player.posy = 0.5f + i;
	game->setup.map[i][j] = '0';
}
