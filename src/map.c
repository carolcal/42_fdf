/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:08:54 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/25 18:53:28 by marvin           ###   ########.fr       */
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
	return (count);
}

static int	get_map_height(char *map_path)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(map_path, O_RDONLY);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

t_map	*get_map(char	*map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = get_map_width(map_path);
	map->height = get_map_height(map_path);
	return (map);
}
