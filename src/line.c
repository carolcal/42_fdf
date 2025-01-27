/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:51 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 15:48:48 by cayamash         ###   ########.fr       */
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
	t_projected	q;

	rad = radiano(ANGLE);
	q.x = ((p.x - p.y) * cos(rad)) * cam->tile + cam->offset_x;
	q.y = ((p.x + p.y) * sin(rad)) * cam->tile + cam->offset_y - (p.z * cam->offset_z);
	return (q);
}

char	**get_line(int fd)
{
	char	*line;
	char	**array;

	line = get_next_line(fd);
	array = ft_split(line, ' ');
	return (array);
}

void	read_map(t_fdf *fdf, char *map_path)
{
	int				fd;
	char			**line;
	t_coordinates	p;

	p.y = 0;
	fd = open(map_path, O_RDONLY);
	while (p.y < fdf->map->height)
	{
		line = get_line(fd);
		p.x = 0;
		while (p.x < fdf->map->width)
		{
			p.z = ft_atoi(line[p.x]);
			ft_printf("x=%i, y=%i, z=%i\n", p.x, p.y, p.z);
			insert_pixels(fdf->img, cal_position(p, fdf->cam));
			p.x++;
		}
		p.y++;
		free_array(line);
	}
	close(fd);
}
