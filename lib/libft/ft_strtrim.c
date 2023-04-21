/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:33:03 by glamy             #+#    #+#             */
/*   Updated: 2019/10/28 10:02:17 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	size_t	i;

	if (!c || !set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*copy;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (checkset(*start, set))
		start++;
	if (start < end)
		end--;
	while (checkset(*end, set))
		end--;
	len = end - start + 1;
	if (!(copy = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (len-- > 0)
		copy[i++] = *start++;
	copy[i] = '\0';
	return (copy);
}
