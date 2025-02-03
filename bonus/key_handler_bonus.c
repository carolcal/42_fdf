/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:41 by marvin            #+#    #+#             */
/*   Updated: 2025/01/31 17:44:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->cam->offset_y -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->cam->offset_y += 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->cam->offset_x -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->cam->offset_x += 25;
}

void	scale(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
	{
		fdf->cam->tile += 0.3;
		fdf->cam->tile_z += 0.02;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
	{
		fdf->cam->tile -= 0.3;
		fdf->cam->tile_z -= 0.02;
	}

void	scale_z(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		fdf->cam->tile_z += 0.02;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
		fdf->cam->tile_z -= 0.02;
}

static void	rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->cam->rotation_angle_y += radiano(15);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->cam->rotation_angle_y -= radiano(15);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->cam->rotation_angle_x += radiano(15);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->cam->rotation_angle_x -= radiano(15);
/* 	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->cam->rotation_angle_z += (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		fdf->cam->rotation_angle_z -= (15 * ONE_DEGREE_IN_RADIUS); */
}