/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:31:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/31 16:23:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1600
# define HEIGHT 900
# define ANGLE 30

//Error Macros
# define INVALID_MAP "ERROR: Invalid Map!"
# define INVALID_COLOR "ERROR: Invalid Color!"
# define EMPTY_MAP "ERROR: Map is empty!"
# define WRONG_USAGE "Execute FDF as follows: ./fdf <map_path>."
# define CAM_ERROR "ERROR: When initializing camera!"
# define FDF_ERROR "ERROR: When initializing fdf!"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct s_projected
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	uint32_t	start_color;
	uint32_t	end_color;
}	t_projected;

typedef struct s_map
{
	int		height;
	int		width;
	float	max_z;
	t_point	**matrix;
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

typedef struct s_draw
{
	int	diff_x;
	int	diff_y;
	int	desloc_x;
	int	desloc_y;
	int	x;
	int	y;
}	t_draw;

//Error & Free
void		handle_error(char *err);
void		validade_file(char *map_path);
void		free_array(char **array);
void		free_all(t_fdf *fdf);
//Utils
char		**get_array_line(int fd);
float		radiano(float graus);
float		ft_abs(float n);
int			array_len(char **array);
//FDF
t_fdf		*init_fdf(char *map_path);
//Map
int			get_map_width(char *map_path);
int			get_map_height(char *map_path);
t_point		**get_map_matrix(char *map_path, t_map *map);
//Color
int			ft_hex_to_int(char *hex);
uint32_t	put_alpha(uint32_t color);
uint32_t	get_color(int z, char *value);
int			get_red(int color);
int			get_green(int color);
int			get_blue(int color);
int			get_alpha(int color);
int			get_rgba(int red, int green, int blue, int alpha);
uint32_t	gradient(int start, int end, int grad_len, int position);
//Camera
float		get_tile_size(t_map *map);
float		get_tile_z(t_map *map);
//Line
void		draw_line(t_projected proj, mlx_image_t *img);
//Render
void		render_map(t_fdf *fdf);

#endif