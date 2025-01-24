/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/24 14:34:50 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	insert_pixels(mlx_image_t *img, int row, int row_index, int line_index)
{
	if (row == 0)
		mlx_put_pixel(img, row_index * 20, line_index * 20, 0xFFFFFFFF);
	else
		mlx_put_pixel(img, row_index * 20, line_index * 20, 0xFF0000FF);
}

void	read_map(mlx_image_t *img, t_map *map, char *map_path)
{
	int		fd;
	char	**line;
	int		row;
	int		line_index;
	int		row_index;

	fd = open(map_path, O_RDONLY);
	line_index = 0;
	while (line_index < map->height)
	{
		line = ft_split(get_next_line(fd), ' ');
		row_index = 0;
		while (row_index < map->width)
		{
			row = ft_atoi(line[row_index]);
			insert_pixels(img, row, row_index, line_index);
			row_index++;
		}
		line_index++;
		free_array(line);
	}
	close(fd);
}
