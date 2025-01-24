/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:01:49 by cayamash          #+#    #+#             */
/*   Updated: 2024/10/24 12:11:26 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*new_node;

	temp = lst;
	new_lst = NULL;
	while (temp != NULL)
	{
		new_node = ft_lstnew((*f)(temp->content));
		if (!new_node)
		{
			(del)(temp);
			(del)(new_node);
			(del)(new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp = temp->next;
	}
	(del)(temp);
	return (new_lst);
}
