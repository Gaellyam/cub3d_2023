/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:25:08 by glamy             #+#    #+#             */
/*   Updated: 2019/10/21 11:23:28 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int				c;
	unsigned int	nbr;

	if (n == 0)
		return (1);
	c = 0;
	nbr = n;
	if (n < 0)
	{
		c++;
		nbr = -n;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	nbr;
	int				sizen;
	int				i;

	sizen = ft_nbrlen(n);
	if (!(s = (char *)malloc(sizeof(char) * (sizen + 1))))
		return (0);
	s[sizen] = '\0';
	i = 0;
	nbr = n;
	if (n < 0)
	{
		i = 1;
		s[0] = '-';
		nbr = -n;
	}
	sizen--;
	while (sizen >= (i ? 1 : 0))
	{
		s[sizen] = nbr % 10 + '0';
		nbr /= 10;
		sizen--;
	}
	return (s);
}
