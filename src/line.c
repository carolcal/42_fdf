/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 08:41:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	insert_pixels(mlx_image_t *img, t_projected q)
{
	/* if (p.z == 0)
		mlx_put_pixel(img, p.y * 20, p.x * 20, 0xFFFFFFFF);
	else */
    ft_printf("x=%i, y=%i\n", q.x, q.y);
    mlx_put_pixel(img, q.y, q.x, 0xFF0000FF); // Cor azul
}

int get_tile_size(t_map *map)
{
	int tile_x;
	int tile_y;

	tile_x = (WIDTH * 0.7) / (map->width * 2);
	tile_y = (HEIGHT * 0.7) / (map->height * 2);
	if(tile_x < tile_y)
		return (tile_x);
	return (tile_y);
}

t_projected	cal_position(t_coordinates p, t_map *map)
{
	int tile_size;
	int offset_x;
	int offset_y;
    t_projected q;
    
	tile_size = get_tile_size(map);
	offset_x = WIDTH / 2 - (map->width * tile_size) / 2;
    offset_y = HEIGHT / 2 - (map->height * tile_size) / 2;
	q.x = ((p.x - p.y) * sqrt(3) / 2) * tile_size + offset_x;
    q.y = ((p.x + p.y) * 0.5 - p.z) * tile_size + offset_y;
    return (q);
} //rever

char	**get_line(char *map_path)
{
	int		fd;
	char	*line;
	char	**array;
	
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	array = ft_split(line, ' ');
	close(fd);
	return (array);
}

void	read_map(mlx_image_t *img, t_map *map, char *map_path)
{
	char	**line;
    t_coordinates   p;

	p.x = 0;
	while (p.x < map->height)
	{
		line = get_line(map_path);
		p.y = 0;
		while (p.y < map->width)
		{
			p.z = ft_atoi(line[p.y]);
			ft_printf("x=%i, y=%i, z=%i\n", p.x, p.y, p.z);
			insert_pixels(img, cal_position(p, map));
			p.y++;
		}
		p.x++;
		free_array(line);
	}
}
