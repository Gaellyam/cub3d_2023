/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:59:11 by glamy             #+#    #+#             */
/*   Updated: 2019/11/05 11:09:45 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	c;
	size_t		nb;

	c = 0;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			c = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		if (c == 1 && nb > 2147483648)
			return (0);
		if (c == 0 && nb > 2147483647)
			return (-1);
		str++;
	}
	return (c ? -nb : nb);
}
