#include "../include/cub3d.h"

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
			ft_printf("On est bien");
		else 
			ft_printf("C la merde");
	}
	free(data);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "cub3D");
	game(&map);
}