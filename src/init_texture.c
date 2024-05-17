#include "../include/cub3d.h"

char    *my_mlx_addr(t_img *texture)
{
   return (mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
   &texture->line_length, &texture->endian));
}

void    *my_mlx_xpm_to_image(char *way, t_map *map, int *j)
{
    void    *texture;

    texture = mlx_xpm_to_image(map -> mlx, way, 64, 64);
    if (texture == NULL)
        *j = 0;
    free(way);
    return (texture);
}

int     set_texture(char *way, t_map *map, int i)
{
    void    *texture;
    int     j;

    j = 1;
    if (ft_strchr(way, ".xpm") == 0)
		return (0);
    if (i == 2)
        map -> no_texture -> img = my_mlx_xpm_to_image(way, map, &j);
    if (i == 3)
        map -> so_texture -> img = my_mlx_xpm_to_image(way, map, &j);
    if (i == 4)
         map -> we_texture -> img = my_mlx_xpm_to_image(way, map, &j);
    if (i == 5)
         map -> ea_texture -> img = my_mlx_xpm_to_image(way, map, &j);
    if (j == 0)
        return (0);
    if (i == 2)
        map -> no_texture -> addr = my_mlx_addr(map->no_texture);
    if (i == 3)
        map -> so_texture -> addr = my_mlx_addr(map->so_texture);
    if (i == 4)
         map -> we_texture -> addr = my_mlx_addr(map->we_texture);
    if (i == 5)
         map -> ea_texture -> addr = my_mlx_addr(map->ea_texture);
    return (1);
}
char	*way_texture(char **tab, char c)
{
    int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == ' ')
			j++;
		if (tab[i][j] == c)
		{
            while (tab[i][j] != '.' && tab[i][j])
                j++;
            break ;
        }
		i++;
	}
    if (!tab[i][j])
        return (NULL);
    return (tab[i] + j);
}

void    init_texture(t_data *data, t_map *map)
{
    int     i;
    char    *way;

    i = 2;
    while (i < 6)
    {
        way = ft_strdup(way_texture(data -> texture_color, CARAC_MAP[i]));
        if (set_texture(way, map, i) == 0)
            return (ft_error_texture("Error\nCan't set texture\n", data, map, i));
        i++;
    }
}
