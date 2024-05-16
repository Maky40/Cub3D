#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH)
		return ;
	if (y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(map -> mlx_img, x, y, color);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_map *map, int ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(map, ray, i++, 0xB99470FF);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(map, ray, i++, 0x89CFF3FF);
}

int	get_color(t_map *map, int flag)
{
	map->ray->ray_ngl = nor_angle(map->ray->ray_ngl);
	if (flag == 0)
	{
		if (map->ray->ray_ngl > M_PI / 2 && map->ray->ray_ngl < 3 * (M_PI / 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (map->ray->ray_ngl > 0 && map->ray->ray_ngl < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	draw_wall(t_map *map, int ray, int t_pix, int b_pix)
{
	int	color;

	color = get_color(map, map->ray->flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(map, ray, t_pix++, color);
}

void	render_wall(t_map *map, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	map->ray->distance *= cos(nor_angle(map->ray->ray_ngl - map->player->dir));
	wall_h = (CUBE_SIZE / map->ray->distance) * ((WIDTH / 2) / tan(map->player->fov_rd / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(map, ray, t_pix, b_pix);
	draw_floor_ceiling(map, ray, t_pix, b_pix);
}
