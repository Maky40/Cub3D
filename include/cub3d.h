
#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include <math.h>
# define CARAC_MAP "10NSWE"
# define HEIGHT 720
# define WIDTH 1280
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define ROT_SPEED 0.10
# define TWO_PI 6.283185
# define PI_3_2 4.712389
# define M_PI_2	1.57079632679489661923
// # define M_PI 3.1415926535897932384626433832795028841
# define CUBE_SIZE 64
# define FOV 60

typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	int		flag;
}				t_ray;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	t_point	map_pos;
	double	dir;
	double	speed;
	int		plyr_x;
	int		plyr_y;
	float	fov_rd;
	// int		rot;
	// int		l_r;
	// int		u_d;
}	t_player;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	t_img		mlx_img;
	t_img		*no_texture;
	t_img		*so_texture;
	t_img		*we_texture;
	t_img		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	int			map_width;
	int			map_height;
	char		**map;
	t_player	*player;
	t_ray		*ray;
}	t_map;

typedef struct s_data
{
	char	**map;
	int		valid_map;
	int		valid_texture_color;
	int		count_letter;
	char	**texture_color;
	int		color_cap;
	int		color_floor;
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
// errors
void		error_map(char *str, t_data *data);
void		ft_error_texture(char *str, t_data *data, t_map *map, int i);
void		error_color(char *str, t_data *data, int fd);
// init texture and color and data
void	init_color(t_data *data, int fd);
int		init_data(char **str, t_data *data);
// raycasting
void	raycasting(t_map *map);
float	get_h_inter(t_map *map, float angl);
float	get_v_inter(t_map *map, float angl);
#endif