/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:57:36 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 09:26:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	draw_horizontal(t_projected proj, t_draw line, mlx_image_t *img)
{
	int	diff;
    //ft_printf("draw line horizontal\n");
	diff = line.diff_x / 2;
	while (line.x != proj.end_x)
	{
        //printf("x: %i, y: %i, color: %d\n",line.x, line.y, proj.start_color);
		mlx_put_pixel(img, line.x, line.y, proj.start_color);
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
	int	diff;
	diff = line.diff_y / 2;
	while (line.y != proj.end_y)
	{
		mlx_put_pixel(img, line.x, line.y, proj.start_color);
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
    //ft_printf("draw line\n");
	if (line.diff_x > line.diff_y)
		draw_horizontal(proj, line, img);
	else
		draw_vertical(proj, line, img);
}