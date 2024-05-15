#include "../include/cub3d.h"

int	is_blocking(t_map *map, int new_x, int new_y)
{
	if (is_blocking_up(map, new_x, new_y))
		return (1);
	if (is_blocking_down(map, new_x, new_y))
		return (1);
	if (is_blocking_right(map, new_x, new_y))
		return (1);
	if (is_blocking_left(map, new_x, new_y))
		return (1);
	return (0);
}

void	move_up(t_map *map)
{
	double	new_x;
	double	new_y;

	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player->map_pos.x + cos(map->player->dir) * map->player->speed;
	new_y = map->player->map_pos.y + sin(map->player->dir) * map->player->speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player->map_pos.x = new_x;
		map->player->map_pos.y = new_y;
	}
	raycasting(map);
}

void	move_down(t_map *map)
{
	double	new_x;
	double	new_y;

	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player->map_pos.x - cos(map->player->dir) * map->player->speed;
	new_y = map->player->map_pos.y - sin(map->player->dir) * map->player->speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player->map_pos.x = new_x;
		map->player->map_pos.y = new_y;
	}
	raycasting(map);
}

void	move_left(t_map *map)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = map->player->speed;
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player->map_pos.x - cos(map->player->dir + M_PI_2) * speed;
	new_y = map->player->map_pos.y - sin(map->player->dir + M_PI_2) * speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player->map_pos.x = new_x;
		map->player->map_pos.y = new_y;
	}
	raycasting(map);
}

void	move_right(t_map *map)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = map->player->speed;
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player->map_pos.x + cos(map->player->dir + M_PI_2) * speed;
	new_y = map->player->map_pos.y + sin(map->player->dir + M_PI_2) * speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player->map_pos.x = new_x;
		map->player->map_pos.y = new_y;
	}
	raycasting(map);
}