#include "../include/cub3d.h"
#include <math.h>

int unit_circle(float angle, char c) // check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
		return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		return (1);
	}
	return (0);
}

int inter_check(float angle, float *inter, float *step, int is_horizon) // check the intersection
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += CUBE_SIZE;
			return (-1);
		}
		*step *= -1;
		}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += CUBE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int wall_hit(float x, float y, t_map *map) // check the wall hit
{
	int x_m;
	int y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / CUBE_SIZE); // get the x position in the map
	y_m = floor (y / CUBE_SIZE); // get the y position in the map
	if ((y_m >= map->map_height || x_m >= map->map_width))
	return (0);
	if (map->map[y_m] && x_m <= (int)strlen(map -> map[y_m]))
		if (map -> map[y_m][x_m] == '1')
			return (0);
	return (1);
}

void raycasting(t_map *map) // cast the rays
{
	double h_inter;
	double v_inter;
	int  ray;

	ray = 0;
	map->ray->ray_ngl = map->player->dir - (map->player->fov_rd / 2); // the start angle
	while (ray < WIDTH) // loop for the rays
	{
		map->ray->flag = 0; // flag for the wall
		h_inter = get_h_inter(map, nor_angle(map->ray->ray_ngl)); // get the horizontal intersection
		v_inter = get_v_inter(map, nor_angle(map->ray->ray_ngl)); // get the vertical intersection
		if (v_inter <= h_inter) // check the distance
			map->ray->distance = v_inter; // get the distance
		else
		{
			map->ray->distance = h_inter; // get the distance
			map->ray->flag = 1; // flag for the wall
		}
		render_wall(map, ray); // render the wall
		ray++; // next ray
		map->ray->ray_ngl += (map->player->fov_rd / WIDTH); // next angle
	}
}