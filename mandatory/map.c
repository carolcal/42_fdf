/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:54 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 16:20:10 by marvin           ###   ########.fr       */
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
	get_next_line(-42);
	close(fd);
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
	get_next_line(-42);
	close(fd);
	return (count);
}

t_point	*fill_matrix_line(char **array, t_map *map, int y)
{
	t_point	*line;
	int		x;

	line = (t_point *)malloc(map->width * sizeof(t_point));
	x = 0;
	while (x < map->width)
	{
		line[x].x = x;
		line[x].y = y;
		line[x].z = ft_atoi(array[x]);
		if (map->max_z < ft_abs(line[x].z))
			map->max_z = ft_abs(line[x].z);
		line[x].color = get_color(line[x].z, array[x]);
		x++;
	}
	return (line);
}

t_point	**get_map_matrix(char *map_path, t_map *map)
{
	int		fd;
	char	**array;
	t_point	**matrix;
	int		y;

	fd = open(map_path, O_RDONLY);
	matrix = (t_point **)malloc(map->height * sizeof(t_point *));
	y = 0;
	while (y < map->height)
	{
		array = get_array_line(fd);
		if (array_len(array) != map->width)
		{
			free_array(array);
			handle_error(INVALID_MAP);
		}
		matrix[y] = fill_matrix_line(array, map, y);
		free_array(array);
		y++;
	}
	return (matrix);
}
