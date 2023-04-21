/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:43:11 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 13:14:52 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_argument(int argc, char *option, int *save)
{
	if (argc > 3)
		str_error("Error:\n Too many arguments given!");
	if (argc < 2)
		str_error("Error:\n Too few arguments given!");
	if (argc == 2)
		*save = FALSE;
	else if (ft_strcmp(option, "--save") == 0)
		*save = TRUE;
	else
		str_error("ERROR:\n Invalid arguments given!");
}

int			main(int argc, char **argv)
{
	t_game	game;
	int		save;

	check_argument(argc, argv[2], &save);
	init_setup(&game);
	open_cub(&game, argv[1]);
	read_info(&game);
	validate_info(&game);
	read_map(&game, game.line);
	validate_map(&game);
	check_all_setup(&game);
	if (save == FALSE)
		run_game(&game);
	else
		screenshot(&game);
	return (0);
}
