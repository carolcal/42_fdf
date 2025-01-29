/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:21:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/29 20:32:31 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_map	*init_map(char	*map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = get_map_width(map_path);
	map->height = get_map_height(map_path);
	map->matrix = get_map_matrix(map_path, map);
	return (map);
}
#include <stdio.h>
t_cam	*init_camera(t_map *map)
{
	t_cam	*cam;
	float	map_offset_x;
	float	map_offset_y;

	cam = malloc(sizeof(t_cam));
	cam->tile = get_tile_size(map);
	map_offset_x = (map->width - map->height) * cam->tile / 2;
	map_offset_y = (map->height + map->width) * cam->tile / 4;
	cam->offset_x = WIDTH / 2 - map_offset_x;
	cam->offset_y = HEIGHT / 2 - map_offset_y;
	cam->tile_z = get_tile_z(map);
	printf("tile: %f, offset_x: %f, offset_y: %f, tile_z: %f", cam->tile, cam->offset_x, cam->offset_y, cam->tile_z);
	return (cam);
}

t_fdf	*init_fdf(char *map_path)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->map = init_map(map_path);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf->mlx)
		handle_error(0);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		handle_error(0);
	fdf->cam = init_camera(fdf->map);
	if (!fdf->cam)
		handle_error(CAM_ERROR);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	return (fdf);
}
