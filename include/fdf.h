/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:31:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 16:47:53 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 900
# define ANGLE 30

typedef struct s_map
{
	int		height;
	int		width;
	float	max_z;

}	t_map;

typedef struct s_cam
{
	float	tile;
	float	offset_x;
	float	offset_y;	
	float	tile_z;
}	t_cam;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	t_cam		*cam;
}	t_fdf;

typedef struct s_coordinates
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_coordinates;

typedef struct s_projected
{
	int	x;
	int	y;
}	t_projected;

void	handle_error(int err);
void	free_array(char **array);
//FDF
t_fdf	*init_fdf(char *map_path);
//Map
int		get_map_width(char *map_path);
int		get_map_height(char *map_path);
float	get_map_max_z(char *map_path);
//Camera
int		get_tile_size(t_map *map);
float	get_tile_z(t_map *map);
//Render
void	render_map(t_fdf *fdf, char *map_path);

#endif