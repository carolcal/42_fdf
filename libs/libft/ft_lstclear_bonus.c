/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:19 by cayamash          #+#    #+#             */
/*   Updated: 2024/10/28 12:04:24 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	while (temp != NULL)
	{
		temp_next = temp->next;
		ft_lstdelone(temp, del);
		temp = NULL;//testar sem esse null
		temp = temp_next;
	}
	*lst = NULL;
}
