/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:23:50 by glamy             #+#    #+#             */
/*   Updated: 2020/09/08 13:34:05 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_seg(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s++;
		}
	}
	return (count);
}

static void	*ft_destroystr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*cp;
	size_t	i;

	if (!(cp = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char		**ft_split(char const *s, char c)
{
	char	**d;
	int		i;
	int		j;

	j = 0;
	if (!s || (!(d = (char **)malloc(sizeof(char *) * (ft_seg(s, c) + 1)))))
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			if (!(d[j++] = ft_strndup(s, i)))
				return (ft_destroystr(d));
			s += i;
		}
	}
	d[j] = NULL;
	return (d);
}
