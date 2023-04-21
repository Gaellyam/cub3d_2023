/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:21:35 by glamy             #+#    #+#             */
/*   Updated: 2019/10/18 08:26:59 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	if (n)
	{
		d = (char *)dst;
		s = (char *)src;
		while (i < n)
		{
			d[i] = s[i];
			if (s[i] == (char)c)
				return ((void *)&d[i + 1]);
			i++;
		}
	}
	return (0);
}
