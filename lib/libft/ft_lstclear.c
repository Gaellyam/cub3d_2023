/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:06:33 by glamy             #+#    #+#             */
/*   Updated: 2020/11/23 14:26:07 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	if (alst == 0 || del == 0)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(*alst, del);
		*alst = tmp;
	}
	*alst = 0;
}
