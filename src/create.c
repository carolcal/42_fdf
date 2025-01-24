/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:21:28 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/24 15:32:20 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_fdf	*init_fdf(char *map_path)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->map = get_map(map_path);
	ft_printf("created map");
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf->mlx)
		handle_error(0);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		handle_error(0);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	return (fdf);
}