#include "../include/cub3d.h"

void	error_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_map(data);
	free_data_texture_color(data);
}
void	ft_error_texture(char *str, t_data *data, t_map *map, int i)
{
	ft_printf("%s\n", str);
	free_data_texture_color(data);
	data -> valid_texture_color = 0;
	// while (i > 2)
	// {
	// 	if (i == 3)
	// 		mlx_destroy_image(map -> mlx, map -> no_texture ->img);
	// 	if (i == 4)
	// 		mlx_destroy_image(map -> mlx, map -> so_texture ->img);
	// 	if (i == 5)
	// 		mlx_destroy_image(map -> mlx, map -> ea_texture ->img);
	// 	i--;
	// }
	while (i > 2)
		i--;
	(void) map;
}

void	error_color(char *str, t_data *data, int fd)
{
	ft_printf("%s", str);
	free_data_texture_color(data);
	free_gnl(fd);
	data -> valid_texture_color = 0;
}
