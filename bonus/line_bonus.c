/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:57:36 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/04 13:47:27 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_horizontal(t_projected proj, t_draw line, mlx_image_t *img)
{
	int			diff;
	uint32_t	color;

	diff = line.diff_x / 2;
	while (line.x != proj.end_x)
	{
		color = gradient(proj.start_color, proj.end_color,
				line.diff_x, ft_abs(line.x - proj.start_x));
		if (line.x < (int)img->width && line.y < (int)img->height
			&& line.y > 0 && line.x > 0)
			mlx_put_pixel(img, line.x, line.y, color);
		diff -= line.diff_y;
		if (diff < 0)
		{
			line.y += line.desloc_y;
			diff += line.diff_x;
		}
		line.x += line.desloc_x;
	}
}

void	draw_vertical(t_projected proj, t_draw line, mlx_image_t *img)
{
	int			diff;
	uint32_t	color;

	diff = line.diff_y / 2;
	while (line.y != proj.end_y)
	{
		color = gradient(proj.start_color, proj.end_color,
				line.diff_y, ft_abs(line.y - proj.start_y));
		if (line.x < (int)img->width && line.y < (int)img->height
			&& line.y > 0 && line.x > 0)
			mlx_put_pixel(img, line.x, line.y, color);
		diff -= line.diff_x;
		if (diff < 0)
		{
			line.x += line.desloc_x;
			diff += line.diff_y;
		}
		line.y += line.desloc_y;
	}
}

void	draw_line(t_projected proj, mlx_image_t *img)
{
	t_draw	line;

	line.diff_x = ft_abs(proj.end_x - proj.start_x);
	line.diff_y = ft_abs(proj.end_y - proj.start_y);
	if (proj.start_x < proj.end_x)
		line.desloc_x = 1;
	else
		line.desloc_x = -1;
	if (proj.start_y < proj.end_y)
		line.desloc_y = 1;
	else
		line.desloc_y = -1;
	line.x = proj.start_x;
	line.y = proj.start_y;
	if (line.diff_x > line.diff_y)
		draw_horizontal(proj, line, img);
	else
		draw_vertical(proj, line, img);
}
