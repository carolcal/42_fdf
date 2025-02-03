/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/01 10:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	handle_key(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	translation(fdf);
	scale(fdf);
	scale_z(fdf);
}

static void	set_menu(t_fdf *fdf)
{
	int	pos;
	int	w;
	int	line;

	w = 0xFFFFFF;
	pos = WIDTH - 150;
	line = HEIGHT;
	while (line--)
	    mlx_put_pixel(fdf->img, pos - 10, line, w);
	/* mlx_string_put(data->mlx, data->win, pos, 25, w, "Close              ESC");
	mlx_string_put(data->mlx, data->win, pos, 50, w, "Zoom     +/- or scroll");
	mlx_string_put(data->mlx, data->win, pos, 75, w, "Move            arrows");
	mlx_string_put(data->mlx, data->win, pos, 95, w, "           left button");
	mlx_string_put(data->mlx, data->win, pos, 125, w, "Rotate    right button");
	mlx_string_put(data->mlx, data->win, pos, 150, w, "Rotate X           W/S");
	mlx_string_put(data->mlx, data->win, pos, 175, w, "Rotate Y           A/D");
	mlx_string_put(data->mlx, data->win, pos, 200, w, "Rotate Z           Q/E");
	mlx_string_put(data->mlx, data->win, pos, 225, w, "Altitude           Z/X");
	mlx_string_put(data->mlx, data->win, pos, 250, w, "Parallel             P");
	mlx_string_put(data->mlx, data->win, pos, 275, w, "Isometric            I");
	mlx_string_put(data->mlx, data->win, pos, 300, w, "Top                  T");
	mlx_string_put(data->mlx, data->win, pos, 325, w, "Front                F");
	mlx_string_put(data->mlx, data->win, pos, 350, w, "Right                R"); */
}

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac != 2)
		handle_error(WRONG_USAGE);
	validade_file(av[1]);
	fdf = init_fdf(av[1]);
	if (!fdf)
		handle_error(FDF_ERROR);
    set_menu(fdf);
	mlx_loop_hook(fdf->mlx, render_map, fdf);
	mlx_loop_hook(fdf->mlx, handle_key, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_all(fdf);
	return (0);
}
