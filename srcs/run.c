/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:50:00 by glamy             #+#    #+#             */
/*   Updated: 2020/11/29 15:28:22 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	run_game(t_game *game)
{
	if (!(game->win = mlx_new_window(game->mlx,
	game->setup.res_width, game->setup.res_height, "cub3d")))
		str_error("ERROR\n Creating windows fail.\n");
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, EVENT_KEY_EXIT, 0, &key_exit, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int		main_loop(t_game *game)
{
	raycast(game);
	raycast_sprite(game, &game->player);
	render(game);
	return (0);
}

void	raycast(t_game *game)
{
	int i;

	i = 0;
	set_ceiling_floor(game);
	while (i < game->setup.res_width)
	{
		init_ray(game, &game->player, &game->ray, i);
		calculate_step(&game->player, &game->ray);
		perform_dda(&game->setup, &game->ray);
		calculate_wall_distance(&game->player, &game->ray);
		calculate_wall_height(game, &game->ray);
		set_wall_tex(&game->player, &game->ray);
		set_wall_color(game, &game->ray, i);
		game->n_buffer[i] = game->ray.perpwalldist;
		i++;
	}
}

void	raycast_sprite(t_game *game, t_player *player)
{
	int i;
	int stripe;

	i = 0;
	sort_sprite(game, player);
	while (i < game->num_sprite)
	{
		translate_sprite(game, player, &game->s_ray, i);
		calculate_sprite_height(game, &game->s_ray);
		calculate_sprite_width(game, &game->s_ray);
		stripe = game->s_ray.draw_start_x;
		while (stripe < game->s_ray.draw_end_x)
		{
			set_sprite_color(game, &game->s_ray, stripe);
			stripe++;
		}
		i++;
	}
}

void	render(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (j < game->setup.res_height)
	{
		i = 0;
		while (i < game->setup.res_width)
		{
			game->img.data[game->setup.res_width * j + i] = game->buf[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
