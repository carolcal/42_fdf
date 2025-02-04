/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/04 14:22:43 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_fdf *fdf)
{
	uint32_t	*pixel;
	uint32_t	index;

	pixel = (uint32_t *)fdf->img->pixels;
	index = fdf->img->height * fdf->img->width;
	while (index--)
		pixel[index] = 0xff000000;
}

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

	if (!start.color || !end.color)
	{
		start.color = gen_color(fdf->map->max_z, fdf->map->min_z, start.z);
		end.color = gen_color(fdf->map->max_z, fdf->map->min_z, end.z);
	}
	rad = radiano(ANGLE);
	proj = isometric(start, end, fdf->cam, rad);
	draw_line(proj, fdf->img);
}

void	render_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	background(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
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
