#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include <MLX42/MLX42.h>
#include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 900

typedef struct  s_map
{
    int height;
    int width;
}   t_map;

typedef struct s_fdf
{
    mlx_t       *mlx;
    mlx_image_t	*img;
    t_map       *map;
}	t_fdf;

typedef struct  s_coordinates
{
    int	x;
	int	y;
	int	z;
} t_coordinates;

typedef struct s_projected
{
	int	x;
	int	y;
} t_projected;

void    handle_error(int err);
void	free_array(char **array);
t_fdf	*init_fdf(char *map_path);
t_map	*get_map(char	*map_path);
void	read_map(mlx_image_t *img, t_map *map, char *map_path);

#endif