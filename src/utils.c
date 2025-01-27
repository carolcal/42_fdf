/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 18:04:45 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(char *err)
{
	if (err == 0)
		ft_printf("%s", mlx_strerror(mlx_errno));
	// else if (err == 1)
	// 	ft_printf("Error: could not open file\n");
	// else if (err == 2)
	// 	ft_printf("Error: unexpected end of file\n");
	// else if (err == 3)
	// 	ft_printf("Error: could not split line\n");
	// else if (err == 4)
	// 	ft_printf("Error: could not read map\n");
	else
		ft_printf("%s\n", err);
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

char	**get_array_line(int fd)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	array = ft_split(line, ' ');
	free (line);
	return (array);
}
