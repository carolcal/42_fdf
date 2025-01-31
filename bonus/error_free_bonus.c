/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:14:37 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 16:14:37 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	handle_error(char *err)
{
	if (err == 0)
		ft_printf("%s", mlx_strerror(mlx_errno));
	else
		ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	validade_file(char *map_path)
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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static void	free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void	free_all(t_fdf *fdf)
{
	if (fdf->map)
	{
		if (fdf->map->matrix)
			free_matrix(fdf->map);
		free(fdf->map);
	}
	if (fdf->cam)
		free(fdf->cam);
	free(fdf);
}
