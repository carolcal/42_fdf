/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/30 14:30:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_projected	isometric(t_point start, t_point end, t_cam *cam, float rad)
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
	t_projected	proj;

	rad = radiano(ANGLE);
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


void	render_line(t_point start, t_point end, t_fdf *fdf)
{
	float		rad;
	t_projected	proj;

	rad = radiano(ANGLE);
	proj = isometric(start, end, fdf->cam, rad);
	draw_line(proj, fdf->img);
}
#include <stdio.h>
void	render_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			//printf("x: %i, y: %i, z: %i, color: %d\n", fdf->map->matrix[y][x].x, fdf->map->matrix[y][x].y, fdf->map->matrix[y][x].z, fdf->map->matrix[y][x].color);
			if (x + 1 < fdf->map->width)
				render_line(fdf->map->matrix[y][x],
					fdf->map->matrix[y][x + 1], fdf);
			if (y + 1 < fdf->map->height)
				render_line(fdf->map->matrix[y][x],
					fdf->map->matrix[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
