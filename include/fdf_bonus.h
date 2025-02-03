/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:31:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/02/03 17:55:05 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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

//View Macros
# define ISOMETRIC 0
# define PARALLEL 1
# define TOP 2
# define FRONT 3
# define LEFT 4
# define RIGHT 5
# define BACK 6

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
	int		view;
	float	angle_x;
	float	angle_y;
	float	angle_z;
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

//Key Handler
void		translation(t_fdf *fdf);
void		scale(t_fdf *fdf);
void		scale_z(t_fdf *fdf);
void		view(t_fdf *fdf);
void		rotation(t_fdf *fdf);
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
void		get_offset(t_map *map, t_cam *cam);
void		reset_cam(t_fdf *fdf);
//Line
void		draw_line(t_projected proj, mlx_image_t *img);
//Projections
t_projected	isometric(t_point start, t_point end, t_cam *cam, float rad);
t_projected	parallel(t_point start, t_point end, t_cam *cam);
t_projected	top(t_point start, t_point end, t_cam *cam);
t_projected	front(t_point start, t_point end, t_cam *cam);
t_projected	right(t_point start, t_point end, t_cam *cam);
t_projected	left(t_point start, t_point end, t_cam *cam);
//Render
t_point		rotate(t_point p, t_cam *cam);
void		render_map(void *param);

#endif