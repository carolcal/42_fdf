/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:18:02 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/30 14:27:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
