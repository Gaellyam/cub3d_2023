/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:57 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 13:02:44 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_check_size_res(t_game *game)
{
	int w_max;
	int h_max;
	int width;

	w_max = 100;
	h_max = 100;
	width = game->setup.res_width;
	mlx_get_screen_size(game->mlx, &w_max, &h_max);
	if (game->setup.res_width > w_max)
		game->setup.res_width = w_max;
	if (game->setup.res_height > h_max)
		game->setup.res_height = h_max;
	if ((game->setup.res_width % TEX_WIDTH) != 0)
	{
		if (game->setup.res_width > TEX_WIDTH)
		{
			while ((width % TEX_WIDTH) != 0)
				width--;
			game->setup.res_width = width;
		}
		else
			game->setup.res_width = TEX_WIDTH;
	}
}

void		parse_resolution(t_game *game, char *line, int flag)
{
	int		i;
	char	**buf;

	i = 0;
	if (!(buf = ft_split(line, ' ')))
		str_error("ERROR:\n Split fail");
	if (!(ft_strcmp(buf[0], "R") == 0))
		str_error("Error:\n Arguments given for resolution not valid!");
	while (buf[i] != '\0')
		i++;
	if (i > 3)
		str_error("Error:\n Too many arguments given for resolution!");
	if (i < 3)
		str_error("Error:\n Too few arguments given for resolution!");
	if (i == 3)
	{
		if (buf[1] == NULL || buf[2] == NULL)
			str_error("Error:\n Resolution arguments not given!");
		if (!str_isdigit(buf[1]) || !str_isdigit(buf[2]))
			str_error("ERROR:\n Not only digit resolution given!");
		game->setup.res_width = ft_atoi(buf[1]);
		game->setup.res_height = ft_atoi(buf[2]);
	}
	ft_check_size_res(game);
	game->setup.param[flag] = flag;
}

static int	isxmpfile(char *filename)
{
	int ret;
	int len;

	ret = 1;
	len = ft_strlen(filename);
	if (len >= 4)
		ret = ft_strncmp(filename + len - 4, ".xpm", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

void		parse_texture(t_game *game, char *line, int flag)
{
	int		fd;
	char	**buf;

	if (!(buf = ft_split(line, ' ')))
		str_error("ERROR:\n Split fail");
	if (buf[2])
		str_error("Error:\n Too many arguments given for texture!");
	if (game->setup.param[flag] != -1)
		str_error("ERROR:\n Double texture given!");
	if (!line || !isxmpfile(buf[1]))
		str_error("ERROR:\n Image format is not .xpm");
	fd = open(buf[1], O_RDONLY);
	if (fd == -1)
		str_error("ERROR:\n Texture paths available!");
	close(fd);
	game->setup.tex.path[flag] = ft_strdup(buf[1]);
	game->setup.param[flag] = flag;
}

void		parse_color(t_game *game, char *line, int flag)
{
	char	**buf;
	int		color;
	int		num_coma;
	int		i;

	num_coma = check_argcolor(line);
	if (num_coma != 2)
		str_error("ERROR:\n Argument color not valid");
	if (line[0] == 'C' || line[0] == 'F')
		line += 1;
	buf = ft_split(line, ',');
	i = 0;
	while (buf[i])
	{
		buf[i] = ft_strtrim(buf[i], " ");
		i++;
	}
	color = check_color(buf, i);
	if (flag == C_F)
		game->setup.tex.floor = color;
	else if (flag == C_C)
		game->setup.tex.ceiling = color;
	game->setup.param[flag] = flag;
}
