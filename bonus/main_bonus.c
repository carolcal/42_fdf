/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/04 14:17:58 by cayamash         ###   ########.fr       */
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
	view(fdf);
	rotation(fdf);
}

static void	render_menu(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "=========FDF=========", 20, 20);
	mlx_put_string(fdf->mlx, "ESC : Quit", 20, 40);
	mlx_put_string(fdf->mlx, "Arrows : Translate", 20, 60);
	mlx_put_string(fdf->mlx, "+/- : Zoom In/Out", 20, 80);
	mlx_put_string(fdf->mlx, "I/O : Change Height", 20, 100);
	mlx_put_string(fdf->mlx, "A/D : Rotate X", 20, 120);
	mlx_put_string(fdf->mlx, "W/S : Rotate Y", 20, 140);
	mlx_put_string(fdf->mlx, "Q/E : Rotate Z", 20, 160);
	mlx_put_string(fdf->mlx, "0 : Isometric View", 20, 180);
	mlx_put_string(fdf->mlx, "1 : Parallel View", 20, 200);
	mlx_put_string(fdf->mlx, "2 : Top View", 20, 220);
	mlx_put_string(fdf->mlx, "3 : Front View", 20, 240);
	mlx_put_string(fdf->mlx, "4 : Left View", 20, 260);
	mlx_put_string(fdf->mlx, "5 : Right View", 20, 280);
}

void	render(t_fdf *fdf)
{
	render_map(fdf);
	render_menu(fdf);
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
	mlx_loop_hook(fdf->mlx, (void (*)(void *))render, fdf);
	mlx_loop_hook(fdf->mlx, handle_key, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_all(fdf);
	return (0);
}
