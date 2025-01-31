#include "fdf.h"

void	handle_error(char *err)
{
	if (err == 0)
		ft_printf("%s", mlx_strerror(mlx_errno));
	else
		ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
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

void    free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void    free_all(t_fdf *fdf)
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
