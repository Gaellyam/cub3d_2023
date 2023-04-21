/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:10:30 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 13:16:00 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_sprite(t_game *game)
{
	int x;
	int y;
	int i;

	i = 0;
	if (!(game->sprite = malloc(sizeof(t_sprite) * game->num_sprite)))
		str_error("ERROR:\n Malloc Fail!");
	y = 0;
	while (y < game->setup.map_height)
	{
		x = 0;
		while (x < game->setup.map_width)
		{
			if (game->setup.map[y][x] == '2')
			{
				set_pos_sprite(game, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	set_pos_sprite(t_game *game, int i, int x, int y)
{
	game->sprite[i].spr_x = 0.5f + x;
	game->sprite[i].spr_y = 0.5f + y;
}

void	sort_sprite(t_game *game, t_player *player)
{
	int i;

	i = 0;
	while (i < game->num_sprite)
	{
		game->sprite[i].spr_distance =
			((player->posx - game->sprite[i].spr_x) *
			(player->posx - game->sprite[i].spr_x)
			+ (player->posy - game->sprite[i].spr_y) *
			(player->posy - game->sprite[i].spr_y));
		i++;
	}
	sort(game);
}

void	sort(t_game *game)
{
	int			i;
	int			j;
	int			max;
	t_sprite	temp;

	i = 0;
	max = 0;
	while (i < game->num_sprite - 1)
	{
		max = i;
		j = i + 1;
		while (j < game->num_sprite)
		{
			if (game->sprite[j].spr_distance > game->sprite[i].spr_distance)
				max = j;
			j++;
		}
		if (i != max)
		{
			temp = game->sprite[i];
			game->sprite[i] = game->sprite[max];
			game->sprite[max] = temp;
		}
		i++;
	}
}

void	set_sprite_color(t_game *game, t_spr_ray *s_ray, int stripe)
{
	int y;
	int draw;
	int color;

	s_ray->tex_x =
		(int)((256 * (stripe - (-s_ray->width / 2 + s_ray->screen_x)) *
			TEX_WIDTH / s_ray->width) / 256);
	if (s_ray->transform_y > 0 && stripe > 0 &&
		stripe < game->setup.res_width &&
		s_ray->transform_y < game->n_buffer[stripe])
	{
		y = s_ray->draw_start_y;
		while (y < s_ray->draw_end_y)
		{
			draw = (y - s_ray->v_move_screen) * 256 -
					game->setup.res_height * 128 + s_ray->height * 128;
			s_ray->tex_y = ((draw * TEX_HEIGHT) / s_ray->height) / 256;
			color = game->setup.tex.tile[C_S][TEX_WIDTH *
			s_ray->tex_y + s_ray->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				game->buf[y][stripe] = color;
			y++;
		}
	}
}
