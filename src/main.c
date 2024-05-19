#include "../include/cub3d.h"

void	get_dir(t_map *map)
{
	int	i;
	int	j;

	i = map -> player -> map_pos.y;
	j = map -> player -> map_pos.x;
	if (map -> map[i][j] == 'N')
		map -> player -> dir = PI_3_2;
	if (map -> map[i][j] == 'S')
		map -> player -> dir = M_PI_2;
	if (map -> map[i][j] == 'W')
		map -> player -> dir = M_PI;
	if (map -> map[i][j] == 'E')
		map -> player -> dir = 0;
}

void	get_pos_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j])
		{
			if (ft_isalpha(map -> map[i][j]) == 1)
			{
				map -> player -> map_pos.x = j;
				map -> player -> map_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_width_height(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map -> map[i])
		i++;
	map -> map_height = i;
	i = 0;
	while (map -> map[i])
	{
		j = 0;
		while (map -> map[i][j])
			j++;
		if (k < j)
			k = j;
		i++;
	}
	map -> map_width = k;
}

void	init_map(t_map *map, t_data *data)
{

	map -> map = duplicate_map2(data -> map);
	free_tab_tab(data -> map);
	map -> floor_color = data -> color_floor;
	map -> ceiling_color = data -> color_cap;
	get_width_height(map);
	get_pos_player(map);
	get_dir(map);
}

int main(int argc, char **argv)
{
	t_data	*data;
	t_map	map;

	data = malloc(sizeof(t_data));
	if (argc != 2)
		ft_printf("Error\nNeed only arg map.cub\n");
	else
	{
		if (init_data(argv, data) == 1)
		{
			init_map(&map, data);
			map.mlx = mlx_init();
			map.mlx_win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "cub3D");
			init_texture(data, &map);
			game(&map);
		}
		else
		{
			free(data);
			return (1);
		}
	}
	return (0);
}
