#include "../include/cub3d.h"

void	error_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_map(data);
	free_data_texture_color(data);
}
void	ft_error_texture(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_texture_color(data);
	if (data -> no_p)
		free (data -> no_p);
	if (data -> so_p)
		free (data -> so_p);
	if (data -> we_p)
		free (data -> we_p);
	if (data -> ea_p)
		free (data -> ea_p);
	free_tab_tab(data -> map);
}

void	error_color(char *str, t_data *data, int fd)
{
	ft_printf("%s", str);
	free_data_texture_color(data);
	free_gnl(fd);
	data -> valid_texture_color = 0;
}
