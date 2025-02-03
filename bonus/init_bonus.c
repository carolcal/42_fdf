/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:21:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/01 10:57:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_map	*init_map(char	*map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->width = get_map_width(map_path);
	map->height = get_map_height(map_path);
	map->max_z = 0;
	map->matrix = get_map_matrix(map_path, map);
	return (map);
}

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
	cam->view = ISOMETRIC;
	cam->rotation_x = 0;
	cam->rotation_y = 0;
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
