#include "../include/cub3d.h"

void	ft_mlx_pixel_put(t_map *map, int x, int y, int color)
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
		ft_mlx_pixel_put(map, ray, i++, map -> ceiling_color);
	i = 0;
	while (i < t_pix)
		ft_mlx_pixel_put(map, ray, i++, map -> floor_color);
}

// int	get_color(t_map *map, int flag)
// {
// 	map->ray->ray_ngl = nor_angle(map->ray->ray_ngl);
// 	if (flag == 0)
// 	{
// 		if (map->ray->ray_ngl > M_PI / 2 && map->ray->ray_ngl < 3 * (M_PI / 2))
// 			return (0xB5B5B5FF);
// 		else
// 			return (0xB5B5B5FF);
// 	}
// 	else
// 	{
// 		if (map->ray->ray_ngl > 0 && map->ray->ray_ngl < M_PI)
// 			return (0xF5F5F5FF);
// 		else
// 			return (0xF5F5F5FF);
// 	}
// }

// void	draw_wall(t_map *map, int ray, int t_pix, int b_pix)
// {
// 	int	color;

// 	color = get_color(map, map->ray->flag);
// 	while (t_pix < b_pix)
// 		ft_mlx_pixel_put(map, ray, t_pix++, color);
// }



int get_texture_color(t_img *texture, int x, int y)
{
    char *dst;

    if (x < 0 || x >= 64 || y < 0 || y >= 64)
        return (0x000000); // Return black if coordinates are out of bounds
    dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    return *(unsigned int *)dst;
}

void draw_wall(t_map *map, int ray, int t_pix, int b_pix)
{
    t_img *texture;
    int color;
    int tex_x;
    int tex_y;
    double wall_x;
    double wall_h = b_pix - t_pix;

    // Determine which texture to use based on the wall hit flag and ray angle
    if (map->ray->flag == 0)
    {
        if (map->ray->ray_ngl > M_PI / 2 && map->ray->ray_ngl < 3 * M_PI / 2)
            texture = map->we_texture;
        else
            texture = map->ea_texture;
    }
    else
    {
        if (map->ray->ray_ngl > 0 && map->ray->ray_ngl < M_PI)
            texture = map->so_texture;
        else
            texture = map->no_texture;
    }

    // Calculate the x coordinate on the texture
    if (map->ray->flag == 0)
        wall_x = map->player->plyr_y + map->ray->distance * sin(map->ray->ray_ngl);
    else
        wall_x = map->player->plyr_x + map->ray->distance * cos(map->ray->ray_ngl);
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * 64);
    if ((map->ray->flag == 0 && map->ray->ray_ngl > M_PI / 2 && map->ray->ray_ngl < 3 * M_PI / 2) || 
        (map->ray->flag == 1 && map->ray->ray_ngl > 0 && map->ray->ray_ngl < M_PI))
        tex_x = 64 - tex_x - 1;

    // Draw the wall with the texture
    while (t_pix < b_pix)
    {
        tex_y = (int)(((t_pix - HEIGHT / 2 + wall_h / 2) * 64) / wall_h);
        color = get_texture_color(texture, tex_x, tex_y);
        ft_mlx_pixel_put(map, ray, t_pix++, color);
    }
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
