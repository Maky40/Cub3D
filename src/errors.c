#include "../include/cub3d.h"

void	error_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_map(data);
	free_data_texture_color(data);
}
void	ft_error_texture(char *str, t_data *data, char **tab)
{
	ft_printf("%s\n", str);
	free_data_texture_color(data);
	free_tab_tab(tab);
	data -> valid_texture_color = 0;
}

void	error_color(char *str, t_data *data)
{
	ft_printf("%s", str);
	free_data_texture_color(data);
	data -> valid_texture_color = 0;
}
