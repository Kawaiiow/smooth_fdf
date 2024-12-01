/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibasri <pibasri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:11:39 by pibasri           #+#    #+#             */
/*   Updated: 2024/11/21 21:30:30 by pibasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "../lib/Libft_pratical_use/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

# define RED 0xFF0000FF
# define GREEN 0x00FFA1FF
# define BLUE 0x0000FFFF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF

# define M_PI 3.14159265358979323846

# define FIX_SCALE 2

/**
 * @brief enum of projectiuon mode
 * 
 * - `ISO` - Isometric projection
 * 
 * - `OTH` - Orthographic projection
 * 
 */
typedef enum e_mode
{
	ISO,
	OTH_T,
	OTH_S,
	OTH_F
}	t_mode;

typedef enum e_axis
{
	X,
	Y,
	Z
}	t_axis;

typedef enum e_error
{
	A_OK,
	CON_ERROR,
	Z_EXCEED
}	t_error;

typedef union u_color
{
	struct
	{
		unsigned char	a;
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
	unsigned char	rgba[4];
	unsigned int	rgb_hex;
}	t_color;

/**
 * @brief 3 Dimension Vector
 * 
 * - double `x` - x coordinate
 * 
 * - double `y` - y coordinate
 * 
 * - double `z` - z coordinate
 * 
 * - t_color `color` - color attributes
 * 
 */
typedef struct s_3v
{
	double		x;
	double		y;
	double		z;
	t_color		color;
}	t_3v;

/**
 * @brief 2 Dimesion Vector
 * use for storing coordinate for display
 * 
 * - int `x` - x coordinate
 * 
 * - int `y` - y coordinate
 * 
 * - t_color `color` - color attributes
 * 
 */
typedef struct s_2axis
{
	int		x;
	int		y;
	t_color	color;
}	t_2axis;

/**
 * @brief 2 Dimesion Vector
 * use for storing coordinate for calculation
 * 
 * - double `x` - x coordinate
 * 
 * - double `y` - y coordinate
 * 
 * - t_color `color` - color attributes
 * 
 */
typedef struct s_2v
{
	double	x;
	double	y;
	t_color	color;
}	t_2v;

/**
 *  @brief 3 x 3 Matrix
 * 
 * 	- t_3v `i` - vector of I
 * 
 * 	- t_3v `j` - vector of J
 * 
 * 	- t_3v `k` - vector of K
 * 
 */
typedef struct s_3x3_matrix
{
	t_3v	i;
	t_3v	j;
	t_3v	k;
}	t_3x3_m;

/**
 * @brief Type of linked list row
 * 
 * - void *`col` - pointer contain data in each row
 * 
 * - struct s_row *`next_row` - pointer to next `t_row`
 * 
 * note : this list will be use for parsing line of strs before going to split
 * and map to int
*/
typedef struct s_row
{
	void			*col;
	struct s_row	*next_row;
}	t_row;

/**
 * @brief Map container
 * 
 * - int `col` - number of column
 * 
 * - int `row` - number of row
 * 
 * - t_row *`raw_map` - container of each line from map store
 * in queue
 * 
 * - t_row *`cur_row` - tail of the queue
 * 
 * - t_3v *`vec_map` - container of each point in vector form
 * 
 * - t_2axis *`point_buf` - Memo for point calculation
 * 
 */
typedef struct s_map
{
	t_error	stat;
	int		col;
	int		row;
	t_row	*raw_map;
	t_row	*cur_row;
	t_3v	*vec_map;
	t_2axis	*point_buf;
}	t_map;

/**
 * @brief container for all properties of the map
 * 
 * - t_map *`map` - struct of which contain the map and its properties
 * 
 * - t_mode	`mode` - Enum of projection mode
 * 
 * - int	`tran_x` - offset on X axis
 * 
 * - int	`tran_y` - offset on Y axis
 * 
 * - double	`x_deg` - rotation angle on X axis
 * 
 * - double	`y_deg` - rotation angle on Y axis
 * 
 * - double	`z_deg` - rotation angle on Z axis
 * 
 * - double	`scale` - scale factor (aka. distance between each point)
 * 
 */
typedef struct s_prop
{
	t_map			*map;
	t_mode			mode;
	short			tran_x;
	short			tran_y;
	double			x_deg;
	double			y_deg;
	double			z_deg;
	unsigned short	scale;
}	t_prop;

/**
 * @brief container of the mlx img and varies
 */
typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_prop		prop;
}	t_fdf;

t_color	new_color(int hex);
int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

int		gradient(t_2axis *cur_pos, t_2axis *start, t_2axis *stop);

void	plot_line(t_fdf *fdf, t_2axis start, t_2axis stop);

// vector operation

void	ft_3vto3x3(t_3x3_m mat, t_3v *vec);
void	ft_itovec(t_3v *vec, double c);
t_3x3_m	iso_rotate_m(double degree, t_axis axis);
t_2v	ft_iso(t_3v vector, t_prop *prop);

// offset
t_2axis	add_offset(t_2v vector, t_prop *prop);

t_2v	scale_mul(t_2v vector, double i);

double	rad(double degree);

void	clear_queue(t_row *raw_map, void (*f)(void *));
void	lst_iter(t_row *row);
void	get_queue(t_map *map, int fd);

void	read_map(t_map *map, int argc, char **argv);
void	init_vector(t_map *map, t_3v *vec_map);

void	render(t_fdf *fdf, t_prop *prop, t_map *map);
void	reframe(t_fdf *fdf, t_prop *prop, t_map *map);

void	move_control(void *param);

#endif
