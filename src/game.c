#include "../include/cub3d.h"

double	angle_rad_conversion(double rad_angle)
{
	if (rad_angle >= TWO_PI)
		rad_angle -= TWO_PI;
	if (rad_angle < 0.0)
		rad_angle += TWO_PI;
	return (rad_angle);
}

void	free_map_struct(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == LEFT_ARROW)
	{
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir -= ROT_SPEED;
		map->player.dir = angle_rad_conversion(map->player.dir);
		//raycasting(map);
	}
	else if (keycode == RIGHT_ARROW)
	{
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir += ROT_SPEED;
		map->player.dir = angle_rad_conversion(map->player.dir);
		//raycasting(map);
	}
	else if (keycode == UP)
		move_forward(map);
	else if (keycode == DOWN)
		move_backward(map);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == RIGHT)
		move_right(map);
	if (keycode == ESC)
		free_map_struct(map);
	return (0);
}


void	game(t_map *map)
{
	mlx_do_key_autorepeaton(map->mlx);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, (1L << 2), free_map_struct, map);
	//raycasting(map);
	mlx_loop(map->mlx);
}