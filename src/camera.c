/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 15:48:48 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_tile_size(t_map *map)
{
	int	tile_x;
	int	tile_y;

	tile_x = WIDTH / map->width;
	tile_y = HEIGHT / map->height;
	if (tile_x < tile_y)
		return (tile_x * 0.5);
	return (tile_y * 0.7);
}

float	get_offset_z(t_map *map)
{
	if (map->max_z <= 20)
		return (10);
	else if (map->max_z > 720)
		return (0.03);
	else
		return (1);
}

t_cam	*init_camera(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->tile = get_tile_size(map);
	cam->offset_x = WIDTH / 2 - (map->width - map->height) * cam->tile / 2;
	cam->offset_y = HEIGHT / 2 - (map->height + map->width) * cam->tile / 4;
	cam->offset_z = get_offset_z(map);
	return (cam);
}
