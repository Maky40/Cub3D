#include "../include/cub3d.h"

void	free_tab_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%d\n", i);
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
	free(data -> map);
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