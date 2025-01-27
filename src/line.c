/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 18:15:54 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	insert_pixels(mlx_image_t *img, t_projected q)
{
	ft_printf("x=%i, y=%i\n", q.x, q.y);
	mlx_put_pixel(img, q.x, q.y, 0xFFFFFFFF);
}

float	radiano(float graus)
{
	float	rad;

	rad = (graus / 180) * 3.1415;
	return (rad);
}

t_projected	cal_position(t_coordinates p, t_cam *cam)
{
	float		rad;
	float		iso_x;
	float		iso_y;
	t_projected	q;

	rad = radiano(ANGLE);
	iso_x = ((p.x - p.y) * cos(rad));
	iso_y = ((p.x + p.y) * sin(rad));
	q.x = (iso_x * cam->tile) + cam->offset_x;
	q.y = (iso_y * cam->tile) + cam->offset_y - (p.z * cam->tile_z);
	return (q);
}

void	render_map(t_fdf *fdf, char *map_path)
{
	int				fd;
	char			**array;
	t_coordinates	p;

	p.y = 0;
	fd = open(map_path, O_RDONLY);
	while (p.y < fdf->map->height)
	{
		array = get_array_line(fd);
		p.x = 0;
		while (p.x < fdf->map->width)
		{
			p.z = ft_atoi(array[p.x]);
			ft_printf("x=%i, y=%i, z=%i\n", p.x, p.y, p.z);
			insert_pixels(fdf->img, cal_position(p, fdf->cam));
			ft_printf("inserted pixel\n");
			p.x++;
		}
		ft_printf("chegou no final da linha\n");
		p.y++;
		free_array(array);
	}
	close(fd);
}
