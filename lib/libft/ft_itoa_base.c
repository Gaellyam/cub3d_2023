/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:00:47 by glamy             #+#    #+#             */
/*   Updated: 2020/09/09 10:24:30 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n, int nbase)
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
		nbr /= nbase;
		c++;
	}
	return (c);
}

char		*ft_itoa_base(int n, int nbase)
{
	char			*s;
	long			nbr;
	int				sizen;
	int				i;

	sizen = ft_nbrlen(n, nbase);
	if (!(s = (char *)malloc(sizeof(char) * (sizen + 1))))
		return (0);
	s[sizen] = '\0';
	i = 0;
	nbr = (long)n;
	if (n < 0)
	{
		i = 1;
		s[0] = '-';
		nbr = -(long)n;
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
