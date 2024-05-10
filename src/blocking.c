#include "../include/cub3d.h"

int	is_blocking_down(t_map *map, int new_x, int new_y)
{
	new_x += 16;
	new_y += 16;
	new_x /= CUBE_SIZE;
	new_y /= CUBE_SIZE;
	if (new_x < 0 || new_x >= map->map_width || new_y < 0 || \
		new_y >= map->map_height)
	{
		return (1);
	}
	if (map->map[new_y][new_x] == '1' || map->map[new_y + 1][new_x + 1] == ' ')
		return (1);
	return (0);
}

int	is_blocking_up(t_map *map, int new_x, int new_y)
{
	new_x -= 16;
	new_y -= 16;
	new_x /= CUBE_SIZE;
	new_y /= CUBE_SIZE;
	if (new_x < 0 || new_x >= map->map_width || new_y < 0 || \
		new_y >= map->map_height)
	{
		return (1);
	}
	if (map->map[new_y][new_x] == '1' || map->map[new_y + 1][new_x + 1] == ' ')
		return (1);
	return (0);
}

int	is_blocking_right(t_map *map, int new_x, int new_y)
{
	new_x += 16;
	new_y -= 16;
	new_x /= CUBE_SIZE;
	new_y /= CUBE_SIZE;
	if (new_x < 0 || new_x >= map->map_width || new_y < 0 || \
		new_y >= map->map_height)
	{
		return (1);
	}
	if (map->map[new_y][new_x] == '1' || map->map[new_y + 1][new_x + 1] == ' ')
		return (1);
	return (0);
}

int	is_blocking_left(t_map *map, int new_x, int new_y)
{
	new_x -= 16;
	new_y += 16;
	new_x /= CUBE_SIZE;
	new_y /= CUBE_SIZE;
	if (new_x < 0 || new_x >= map->map_width || new_y < 0 || \
		new_y >= map->map_height)
	{
		return (1);
	}
	if (map->map[new_y][new_x] == '1' || map->map[new_y + 1][new_x + 1] == ' ')
		return (1);
	return (0);
}