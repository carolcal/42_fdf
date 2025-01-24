/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/24 14:35:26 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"


static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int ac, char *av[])
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf = init_fdf(av[1]);
		if (!fdf)
			handle_error(0);
		read_map(fdf->img, fdf->map, av[1]);
		mlx_loop_hook(fdf->mlx, ft_hook, fdf->mlx);
		mlx_loop(fdf->mlx);
		mlx_terminate(fdf->mlx);
	}
	return (0);
}
