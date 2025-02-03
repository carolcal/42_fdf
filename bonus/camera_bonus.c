/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 17:55:37 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

float	get_tile_size(t_map *map)
{
	float	tile_x;
	float	tile_y;

	tile_x = WIDTH / map->width;
	tile_y = HEIGHT / map->height;
	if (tile_x < tile_y && tile_x > 2)
		return (tile_x * 0.5);
	if (tile_y > 2)
		return (tile_y * 0.5);
	return (1);
}

float	get_tile_z(t_map *map)
{
	if (map->max_z <= 20)
		return (10);
	else if (map->max_z > 720)
		return (0.2);
	else
		return (1);
}

void	get_offset(t_map *map, t_cam *cam)
{
	float	map_offset_x;
	float	map_offset_y;

	if (cam->view == ISOMETRIC)
	{
		map_offset_x = (map->width - map->height) * cam->tile / 2;
		map_offset_y = (map->height + map->width) * cam->tile / 4;
		cam->offset_x = WIDTH / 2 - map_offset_x;
		cam->offset_y = HEIGHT / 2 - map_offset_y;
	}
	else if (cam->view == PARALLEL || cam->view == TOP)
	{
		map_offset_x = map->width * cam->tile / 2;
		map_offset_y = (map->height + map->width) * cam->tile / 4;
		cam->offset_x = WIDTH / 2 - map_offset_x;
		cam->offset_y = HEIGHT / 2 - map_offset_y;
	}
	else
	{
		map_offset_x = map->height * cam->tile / 2;
		map_offset_y = map->max_z * cam->tile_z / 4;
		cam->offset_x = WIDTH / 2 - map_offset_x;
		cam->offset_y = HEIGHT / 2 - map_offset_y;
	}
}

void	reset_cam(t_fdf *fdf)
{
	fdf->cam->angle_x = 0;
	fdf->cam->angle_y = 0;
	fdf->cam->angle_z = 0;
	get_offset(fdf->map, fdf->cam);
}
