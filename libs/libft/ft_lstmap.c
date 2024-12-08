/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:59:20 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/27 02:09:38 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lmap;

	lmap = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&lmap, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		ft_lstadd_back(&lmap, new);
		lst = lst->next;
	}
	return (lmap);
}
