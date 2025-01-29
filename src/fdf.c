/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:25 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/29 18:56:13 by cayamash         ###   ########.fr       */
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
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + len - 4, ".fdf", 4) != 0)
		handle_error(INVALID_MAP);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		handle_error(INVALID_MAP);
	}
	content = get_next_line(fd);
	if (content == NULL)
	{
		free(content);
		close(fd);
		handle_error(EMPTY_MAP);
	}
	free (content);
	get_next_line(-42);
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
	render_map(fdf);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (0);
}
