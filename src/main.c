#include "../include/cub3d.h"

int	ft_end(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_image(data->mlx, data->img_ea.mlx_img);
	mlx_destroy_image(data->mlx, data->img_n.mlx_img);
	mlx_destroy_image(data->mlx, data->img_so.mlx_img);
	mlx_destroy_image(data->mlx, data->img_we.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	get_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data -> map[i])
	{
		ft_printf("%s\n", data -> map[i]);
		j = 0;
		while (data -> map[i][j])
		{
			if (ft_isalpha(data -> map[i][j]) == 1)
			{
				data -> x = j + 0.5;
				data -> y = i + 0.5;
				data -> start_player = data -> map[i][j];
				data -> map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	init_data2(t_data *data)
{
	get_pos_player(data);
	init_texture(data);
}

int main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc != 2)
		ft_printf("Error\nNeed only arg map.cub\n");
	else
	{
		if (init_data(argv, data) == 1)
		{
			init_data2(data);
			game(data);
			free_data(data);
		}
		else
		{
			free(data);
			return (1);
		}
	}
	return (0);
}
