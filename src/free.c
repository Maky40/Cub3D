#include "../include/cub3d.h"

void	free_tab_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	free_data_map(t_data *data)
{
	free_tab_tab(data -> map);
	// free(data -> map);
	data -> map = NULL;
	return ;
}

void	free_data_texture_color(t_data *data)
{
	free_tab_tab(data -> texture_color);
	// free(data -> texture_color);
	data -> texture_color = NULL;
	return ;
}

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
void	free_data(t_data *data)
{
	if (data->no_p)
		free(data->no_p);
	if (data->we_p)
		free(data->we_p);
	if (data->ea_p)
		free(data->ea_p);
	if (data->so_p)
		free(data->so_p);
	free_tab_tab(data->map);
	data->map = 0;
}
void	free_error(t_data *data, char *s)
{
	free_data(data);
	data->no_p = 0;
	data->we_p = 0;
	data->ea_p = 0;
	data->so_p = 0;
	ft_printf("%s", s);
}

int	ft_finish(t_data *data)
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
	// if (data->file)
	// 	free_error(data, "Fin du jeu\n");
	exit(0);
}