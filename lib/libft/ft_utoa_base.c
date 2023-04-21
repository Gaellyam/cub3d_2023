/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:04:15 by glamy             #+#    #+#             */
/*   Updated: 2020/09/08 09:07:09 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unbrlen(unsigned long n, int nbase)
{
	int				c;
	unsigned long	nbr;

	if (n == 0)
		return (1);
	c = 0;
	nbr = n;
	while (nbr > 0)
	{
		nbr /= nbase;
		c++;
	}
	return (c);
}

char		*ft_utoa_base(unsigned long n, char *base, int nbase)
{
	char			*s;
	unsigned long	nbr;
	int				sizen;

	sizen = ft_unbrlen(n, nbase);
	if (!(s = (char *)malloc(sizeof(char) * (sizen + 1))))
		return (0);
	s[sizen] = '\0';
	nbr = n;
	sizen--;
	while (sizen >= 0)
	{
		s[sizen] = base[nbr % nbase];
		nbr /= nbase;
		sizen--;
	}
	return (s);
}
