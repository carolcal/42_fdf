/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 18:27:24 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

static void	validade_file(char *map_path)
{
	int		fd;
	char	*content;

	if (ft_strnstr(map_path, ".fdf", ft_strlen(map_path)) == NULL)
		handle_error(INVALID_MAP);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		handle_error(INVALID_MAP);
	content = get_next_line(fd);
	if (content == NULL)
		handle_error(EMPTY_MAP);
	free (content);
	close (fd);
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
	render_map(fdf, av[1]);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (0);
}
