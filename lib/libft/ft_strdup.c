/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:02:58 by glamy             #+#    #+#             */
/*   Updated: 2019/10/15 15:49:54 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		sz;

	sz = ft_strlen(s1) + 1;
	if (!(c = malloc(sizeof(char) * sz)))
		return (c);
	return (ft_memcpy(c, s1, sz));
}
