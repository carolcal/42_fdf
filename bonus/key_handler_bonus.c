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
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
	{
		fdf->cam->tile += 0.3;
		fdf->cam->tile_z += 0.02;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
	{
		fdf->cam->tile -= 0.3;
		fdf->cam->tile_z -= 0.02;
	}
}

void	scale_z(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		fdf->cam->tile_z += 0.02;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
		fdf->cam->tile_z -= 0.02;
}

void	view(t_fdf *fdf)
{
	int	original_view;

	original_view = fdf->cam->view;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_0))
		fdf->cam->view = ISOMETRIC;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_1))
		fdf->cam->view = PARALLEL;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_2))
		fdf->cam->view = TOP;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_3))
		fdf->cam->view = FRONT;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_4)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_4))
		fdf->cam->view = RIGHT;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_5)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_KP_5))
		fdf->cam->view = LEFT;
	if (original_view != fdf->cam->view)
		reset_cam(fdf);
}

void	rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->cam->angle_y += radiano(5);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->cam->angle_y -= radiano(5);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->cam->angle_x += radiano(5);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->cam->angle_x -= radiano(5);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->cam->angle_z += radiano(5);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		fdf->cam->angle_z -= radiano(5);
}
