/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:30:58 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 17:59:10 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_projected	top(t_point start, t_point end, t_cam *cam)
{
	t_projected	proj;

	proj.start_x = (start.x * cam->tile) + cam->offset_x;
	proj.start_y = (start.y * cam->tile) + cam->offset_y;
	proj.start_color = start.color;
	proj.end_x = (end.x * cam->tile) + cam->offset_x;
	proj.end_y = (end.y * cam->tile) + cam->offset_y;
	proj.end_color = end.color;
	return (proj);
}

t_projected	front(t_point start, t_point end, t_cam *cam)
{
	t_projected	proj;

	proj.start_x = (start.x * cam->tile) + cam->offset_x;
	proj.start_y = cam->offset_y - (start.z * cam->tile_z);
	proj.start_color = start.color;
	proj.end_x = (end.x * cam->tile) + cam->offset_x;
	proj.end_y = cam->offset_y - (end.z * cam->tile_z);
	proj.end_color = end.color;
	return (proj);
}

t_projected	right(t_point start, t_point end, t_cam *cam)
{
	t_projected	proj;

	proj.start_x = (cam->offset_x * 2) - (start.y * cam->tile);
	proj.start_y = cam->offset_y - (start.z * cam->tile_z);
	proj.start_color = start.color;
	proj.end_x = (cam->offset_x * 2) - (end.y * cam->tile);
	proj.end_y = cam->offset_y - (end.z * cam->tile_z);
	proj.end_color = end.color;
	return (proj);
}

t_projected	left(t_point start, t_point end, t_cam *cam)
{
	t_projected	proj;

	proj.start_x = cam->offset_x + (start.y * cam->tile);
	proj.start_y = cam->offset_y - (start.z * cam->tile_z);
	proj.start_color = start.color;
	proj.end_x = cam->offset_x + (end.y * cam->tile);
	proj.end_y = cam->offset_y - (end.z * cam->tile_z);
	proj.end_color = end.color;
	return (proj);
}
