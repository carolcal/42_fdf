/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 18:00:08 by cayamash         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac != 2)
		handle_error(WRONG_USAGE);
	validade_file(av[1]);
	fdf = init_fdf(av[1]);
	if (!fdf)
		handle_error(FDF_ERROR);
	mlx_loop_hook(fdf->mlx, render_map, fdf);
	mlx_loop_hook(fdf->mlx, handle_key, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_all(fdf);
	return (0);
}
