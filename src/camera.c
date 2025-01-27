/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 16:17:15 by cayamash         ###   ########.fr       */
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
	return (tile_y * 0.5);
}

float	get_tile_z(t_map *map)
{
	if (map->max_z <= 20)
		return (10);
	else if (map->max_z > 720)
		return (0.03);
	else
		return (1);
}
