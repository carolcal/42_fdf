/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 15:59:57 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(int err)
{
	if (err == 0)
		ft_printf("%s", mlx_strerror(mlx_errno));
	else if (err == 1)
		ft_printf("Error: could not open file\n");
	else if (err == 2)
		ft_printf("Error: unexpected end of file\n");
	else if (err == 3)
		ft_printf("Error: could not split line\n");
	else if (err == 4)
		ft_printf("Error: could not read map\n");
	exit(EXIT_FAILURE);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
