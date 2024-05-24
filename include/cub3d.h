/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:49:59 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 11:53:38 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# define CARAC_MAP "10NSWE"
# define WIDTH 1920
# define HEIGHT 1080
# define TEXTURE 50

typedef struct s_img
{
	int		height;
	int		width;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_moves
{
	int		move_forward;
	int		move_back;
	int		step_to_left;
	int		step_to_right;
	int		rotate_left;
	int		rotate_right;
	double	move_speed;
	double	rotate_speed;
}	t_moves;

typedef struct s_text
{
	int		n_text;
	double	step;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		color;
	double	wall_x;
}				t_text;

typedef struct s_ray
{
	double	camerax;
	double	ray_dirx;
	double	ray_diry;
	double	ray_dirx0;
	double	ray_diry0;
	double	ray_dirx1;
	double	ray_diry1;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_wall_dist;
	int		mapx;
	int		mapy;
	double	step;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		var_x;
}	t_ray;

typedef struct s_data
{
	char	**map;
	int		valid_map;
	int		valid_texture_color;
	int		count_letter;
	char	**texture_color;
	int		color_cap;
	int		color_floor;
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		fl;
	int		ce;
	int		rx;
	int		ry;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	p_angle;
	char	*no_p;
	char	*so_p;
	char	*we_p;
	char	*ea_p;
	char	start_player;
	t_img	img;
	t_img	img_n;
	t_img	img_so;
	t_img	img_ea;
	t_img	img_we;
	t_moves	moves;
	t_ray	ray;
	t_text	texture;
}				t_data;

// check map
int		check_map(t_data *data);
char	**duplicate_map(char **map1);
int		check_char(char c, t_data *data);
// free
void	free_data_map(t_data *data);
void	free_data_texture_color(t_data *data);
void	free_tab_tab(char **tab);
void	free_gnl(int fd);
void	free_data(t_data *data);
void	free_data2(t_data *data);
// errors
void	error_map(char *str, t_data *data);
void	error_color(char *str, t_data *data, int fd);
void	ft_error_texture(char *str, t_data *data);
// init texture and color and data
void	init_color(t_data *data, int fd);
int		init_data(char **str, t_data *data);
void	init_texture(t_data *data);
int		text_check(t_data *data);
int		way_texture(char *tab);
int		check_name_texture(t_data *data);
// raycasting
void	init_ray(t_data *data);
void	raycasting1(t_data *data);
void	raycasting2(t_data *data);
void	raycasting3(t_data *data);
void	raycasting4(t_data *data);
void	raycasting5(t_data *data);
void	raycasting_hit(t_data *data);
// render
void	texture_choice(t_data *data);
void	texture_choice2(t_data *data);
void	img_init(t_data *data);
// movements
void	ft_rotate1(t_data *data);
void	ft_moves_ad(t_data *data);
void	ft_moves_ws(t_data *data);
// blocking
// main
// mlx
void	game(t_data *data);
int		ft_end(t_data *data);
int		handle_input_release(int keysym, t_data *data);
int		handle_input(int keysym, t_data *data);
char	**duplicate_map2(char **map1);

#endif