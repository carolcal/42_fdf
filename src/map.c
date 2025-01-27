/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:54 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:50 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_width(char *map_path)
{
	int		fd;
	char	**array;
	int		count;

	fd = open(map_path, O_RDONLY);
	array = get_array_line(fd);
	count = 0;
	while (array[count] != NULL)
		count++;
	free_array(array);
	close(fd);
	ft_printf("width: %i\n", count);
	return (count);
}

int	get_map_height(char *map_path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(map_path, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_printf("height: %i\n", count);
	return (count);
}

static int	get_max_z(char	*z, int max_z)
{
	int	curr_z;

	curr_z = ft_atoi(z);
	if (curr_z < 0)
		curr_z = -curr_z;
	if (max_z < curr_z)
		return (curr_z);
	return (max_z);
}

float	get_map_max_z(char *map_path)
{
	int		fd;
	char	**array;
	int		max_z;
	int		i;

	fd = open(map_path, O_RDONLY);
	max_z = 0;
	array = get_array_line(fd);
	while (array != NULL)
	{
		i = 0;
		while (array[i] != NULL)
		{
			max_z = get_max_z(array[i], max_z);
			i++;
		}
		free_array(array);
		array = get_array_line(fd);
	}
	close(fd);
	return (max_z);
}
