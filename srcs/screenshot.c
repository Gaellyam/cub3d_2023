/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:41:37 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 09:55:49 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	screenshot(t_game *game)
{
	int	fd;
	int	size;

	raycast(game);
	raycast_sprite(game, &game->player);
	size = 54 + 3 * game->setup.res_width * game->setup.res_height;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 00755);
	if (fd < 0)
		str_error("ERROR:\n Capture Failure!");
	write_bmp_header(game, fd, size);
	write_data(game, fd);
	close(fd);
	str_error("SAVE: Screenshot Saved Successfully!");
}

void	write_bmp_header(t_game *game, int fd, int size)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	convert_int_to_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	convert_int_to_char(header + 18, game->setup.res_width);
	convert_int_to_char(header + 22, game->setup.res_height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	convert_int_to_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

void	write_data(t_game *game, int fd)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					pad;

	i = game->setup.res_height;
	pad = (4 - (game->setup.res_width * 3) % 4) % 4;
	while (i >= 0)
	{
		j = 0;
		while (j < game->setup.res_width)
		{
			write(fd, &(game->buf[i][j]), 3);
			if (pad > 0)
				write(fd, &zero, pad);
			j++;
		}
		i--;
	}
}
