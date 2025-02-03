/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:11:21 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 17:58:40 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_point	rotate_x(t_point p, t_cam *cam)
{
	t_point	rotated;

	rotated.x = p.x;
	rotated.y = p.y * cos(cam->angle_x) - p.z * sin(cam->angle_x);
	rotated.z = p.y * sin(cam->angle_x) + p.z * cos(cam->angle_x);
	rotated.color = p.color;
	return (rotated);
}

static t_point	rotate_y(t_point p, t_cam *cam)
{
	t_point	rotated;

	rotated.x = p.x * cos(cam->angle_y) + p.z * sin(cam->angle_y);
	rotated.y = p.y;
	rotated.z = -p.x * sin(cam->angle_y) + p.z * cos(cam->angle_y);
	rotated.color = p.color;
	return (rotated);
}

static t_point	rotate_z(t_point p, t_cam *cam)
{
	t_point	rotated;

	rotated.x = p.x * cos(cam->angle_z) - p.y * sin(cam->angle_z);
	rotated.y = p.x * sin(cam->angle_z) + p.y * cos(cam->angle_z);
	rotated.z = p.z;
	rotated.color = p.color;
	return (rotated);
}

t_point	rotate(t_point p, t_cam *cam)
{
	p = rotate_x(p, cam);
	p = rotate_y(p, cam);
	p = rotate_z(p, cam);
	return (p);
}
