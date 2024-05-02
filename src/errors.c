#include "../include/cub3d.h"

void	error_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_map(data);
	free_data_texture(data);
	return (1);
}
void	ft_error_texture(char **str, t_data *data, char **tab)
{
	ft_printf("%s\n", str);
	free_data_texture(data);
	free_tab_tab(tab);
	data -> valid_texture_color = 0;
}
