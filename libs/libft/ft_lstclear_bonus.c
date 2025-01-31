/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:34:19 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 16:25:13 by marvin           ###   ########.fr       */
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
		temp = NULL;
		temp = temp_next;
	}
	*lst = NULL;
}
