/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_projections_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:41:22 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 15:32:01 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_projected	isometric(t_point start, t_point end, t_cam *cam, float rad)
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
	t_projected	proj;

	x0 = ((start.x - start.y) * cos(rad));
	y0 = ((start.x + start.y) * sin(rad));
	proj.start_x = (x0 * cam->tile) + cam->offset_x;
	proj.start_y = (y0 * cam->tile) + cam->offset_y - (start.z * cam->tile_z);
	proj.start_color = start.color;
	x1 = ((end.x - end.y) * cos(rad));
	y1 = ((end.x + end.y) * sin(rad));
	proj.end_x = (x1 * cam->tile) + cam->offset_x;
	proj.end_y = (y1 * cam->tile) + cam->offset_y - (end.z * cam->tile_z);
	proj.end_color = end.color;
	return (proj);
}

t_projected	parallel(t_point start, t_point end, t_cam *cam)
{
	float		z0;
	float		z1;
	t_projected	proj;

	z0 = (start.z * cam->tile_z);
	proj.start_x = (start.x * cam->tile) + cam->offset_x;
	proj.start_y = (start.y * cam->tile) + cam->offset_y - z0;
	proj.start_color = start.color;
	z1 = (end.z * cam->tile_z);
	proj.end_x = (end.x * cam->tile) + cam->offset_x;
	proj.end_y = (end.y * cam->tile) + cam->offset_y - z1;
	proj.end_color = end.color;
	return (proj);
}
