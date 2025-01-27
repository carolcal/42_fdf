/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:54 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 15:30:35 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_width(char *map_path)
{
	int		fd;
	char	**line;
	int		count;

	fd = open(map_path, O_RDONLY);
	line = ft_split(get_next_line(fd), ' ');
	count = 0;
	while (line[count] != NULL)
		count++;
	free_array(line);
	close(fd);
	ft_printf("width: %i\n", count);
	return (count);
}

static int	get_map_height(char *map_path)
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

char	**get_array_line(int fd)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	ft_printf("line: %s", line);
	if (line == NULL)
		return (NULL);
	array = ft_split(line, ' ');
	free(line); 
	return (array);
}

int	get_max_z(char	*z, int max_z)
{
	int	curr_z;

	curr_z = ft_atoi(z);
	if (curr_z < 0)
		curr_z = -curr_z;
	if (max_z < curr_z)
		return (curr_z);
	return (max_z);
}

static float	get_map_max_z(char *map_path)
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

t_map	*get_map(char	*map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = get_map_width(map_path);
	map->height = get_map_height(map_path);
	map->max_z = get_map_max_z(map_path);
	return (map);
}
