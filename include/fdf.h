/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:31:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/27 15:48:48 by cayamash         ###   ########.fr       */
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
	float	offset_z;
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
t_fdf	*init_fdf(char *map_path);
t_map	*get_map(char	*map_path);
t_cam	*init_camera(t_map *map);
void	read_map(t_fdf *fdf, char *map_path);

#endif