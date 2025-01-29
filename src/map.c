/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:54 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/29 20:17:18 by cayamash         ###   ########.fr       */
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

uint32_t	get_color(int z)
{
	if (z <= 0)
		return (put_alpha(0xFFFFFF));
	else
		return (put_alpha(0x0000FF));
}

t_point	*fill_matrix_line(char **array, t_map *map, int y)
{
	t_point	*line;
	int		x;
	char	**value;

	line = (t_point *)malloc(map->width * sizeof(t_point));
	x = 0;
	while (x < map->width)
	{
		line[x].x = x;
		line[x].y = y;
		value = ft_split(array[x], ',');
		line[x].z = ft_atoi(value[0]);
		if (map->max_z < ft_abs(line[x].z))
			map->max_z = ft_abs(line[x].z);
		if (value[1])
		{
			//ft_printf("x: %i, y:%i, color_before: %s, ", x, y, value[1]);
			line[x].color = put_alpha(ft_hex_to_int(value[1]));
			//ft_printf("color_after: %d\n", line[x].color);
		}
		else
			line[x].color = get_color(line[x].z);
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
		y++;
	}
	ft_printf("matrix done!\n");
	return (matrix);
}
