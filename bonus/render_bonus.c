/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:50 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	background(t_fdf *fdf)
{
	uint32_t	*pixel;
	uint32_t	index;

	pixel = (uint32_t *)fdf->img->pixels;
	index = fdf->img->height * fdf->img->width;
	while (index--)
		pixel[index] = 0xff000000;
}

t_projected	get_projection(t_point start, t_point end, t_cam *cam)
{
	float	rad;

	rad = radiano(ANGLE);
	if (cam->view == PARALLEL)
		return (parallel(start, end, cam));
	else if (cam->view == TOP)
		return (top(start, end, cam));
	else if (cam->view == FRONT)
		return (front(start, end, cam));
	else if (cam->view == RIGHT)
		return (right(start, end, cam));
	else if (cam->view == LEFT)
		return (left(start, end, cam));
	else
		return (isometric(start, end, cam, rad));
}

void	render_line(t_point start, t_point end, t_fdf *fdf)
{
	t_projected	proj;

	start = rotate(start, fdf->cam);
	end = rotate(end, fdf->cam);
	proj = get_projection(start, end, fdf->cam);
	draw_line(proj, fdf->img);
}

void	render_map(void *param)
{
	int		x;
	int		y;
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
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
