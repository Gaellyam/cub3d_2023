/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:17 by glamy             #+#    #+#             */
/*   Updated: 2020/11/29 18:38:49 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		str_error("EXIT GAME\n");
	else if (keycode == KEY_W)
		move_front_back(game, game->player.move_speed);
	else if (keycode == KEY_S)
		move_front_back(game, -game->player.move_speed);
	else if (keycode == KEY_A)
		move_left_right(game, game->player.move_speed);
	else if (keycode == KEY_D)
		move_left_right(game, -game->player.move_speed);
	else if (keycode == KEY_RIGHT)
		rotate_player(&game->player, game->player.rot_speed);
	else if (keycode == KEY_LEFT)
		rotate_player(&game->player, -game->player.rot_speed);
	return (0);
}

int	key_exit(void *param)
{
	t_game *game;

	game = (t_game *)param;
	str_error("EXIT GAME\n");
	return (0);
}
