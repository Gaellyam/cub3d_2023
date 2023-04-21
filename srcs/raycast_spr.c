/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_spr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:59:41 by glamy             #+#    #+#             */
/*   Updated: 2020/11/25 14:01:03 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	translate_sprite(t_game *game, t_player *player,
t_spr_ray *s_ray, int i)
{
	double v_mode;

	v_mode = 0.0;
	s_ray->x = game->sprite[i].spr_x - player->posx;
	s_ray->y = game->sprite[i].spr_y - player->posy;
	s_ray->inversion_detection = 1.0 / (player->plane_x *
	player->dir_y - player->dir_x * player->plane_y);
	s_ray->transform_x = s_ray->inversion_detection *
	(player->dir_y * s_ray->x - player->dir_x * s_ray->y);
	s_ray->transform_y = s_ray->inversion_detection *
	(-player->plane_y * s_ray->x + player->plane_x * s_ray->y);
	s_ray->screen_x = (int)((game->setup.res_width / 2) *
	(1 - s_ray->transform_x / s_ray->transform_y));
	s_ray->v_move_screen = (int)(v_mode / s_ray->transform_y);
}

void	calculate_sprite_height(t_game *game, t_spr_ray *s_ray)
{
	int v_div;

	v_div = 1;
	s_ray->height = (int)fabs((game->setup.res_height /
	s_ray->transform_y) / v_div);
	s_ray->draw_start_y = -s_ray->height / 2 +
	game->setup.res_height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_start_y < 0)
		s_ray->draw_start_y = 0;
	s_ray->draw_end_y = s_ray->height / 2 +
	game->setup.res_height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_end_y >= game->setup.res_height)
		s_ray->draw_end_y = game->setup.res_height - 1;
}

void	calculate_sprite_width(t_game *game, t_spr_ray *s_ray)
{
	int u_div;

	u_div = 1;
	s_ray->width = (int)fabs((game->setup.res_height /
	s_ray->transform_y) / u_div);
	s_ray->draw_start_x = -s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_start_x < 0)
		s_ray->draw_start_x = 0;
	s_ray->draw_end_x = s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_end_x >= game->setup.res_width)
		s_ray->draw_end_x = game->setup.res_width - 1;
}
