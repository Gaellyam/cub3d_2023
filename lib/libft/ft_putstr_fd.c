/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:21:44 by glamy             #+#    #+#             */
/*   Updated: 2019/10/22 15:29:00 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
}
