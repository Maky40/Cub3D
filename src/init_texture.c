#include "../include/cub3d.h"

void    my_mlx_addr(t_img *texture, int* addr)
{
	// address = (int *) mlx_get_data_address(data()->img2[i].pointer_to_image,
	// 		&data()->img2[i].bits_per_pixel, &data()->img2[i].line_length,
	// 		&data()->img2[i].endian);
	// 	data()->img2[i].address = address;
	ft_printf("img = %p\n", texture -> img);
   addr = (int *) mlx_get_data_addr(texture->img, &(texture->bits_per_pixel), \
   &(texture->line_length), &(texture->endian));
   if (addr)
	ft_printf("Marche\n");
}

void    my_mlx_xpm_to_image(char *way, t_map *map, int *j, void *texture)
{
	int		k;

	k = 64;
    texture = mlx_xpm_file_to_image(map -> mlx, way, &k, &k);
    if (!texture)
	{
		*j = 0;
		ft_printf("texture pas set\n");
	}

    free(way);
}

int     set_texture(char *way, t_map *map, int i)
{
    int     j;

    j = 1;
    if (ft_strchr(way, ".xpm") == 0)
		return (0);
    if (i == 2)
       my_mlx_xpm_to_image(way, map, &j, map -> no_texture -> img);
    if (i == 3)
        my_mlx_xpm_to_image(way, map, &j, map -> so_texture -> img);
    if (i == 4)
        my_mlx_xpm_to_image(way, map, &j,  map -> we_texture -> img);
    if (i == 5)
         my_mlx_xpm_to_image(way, map, &j, map -> ea_texture -> img);
    if (j == 0)
	{
        return (0);
	}
	ft_printf("KOUKOU\n");
    if (i == 2)
        my_mlx_addr(map->no_texture,map -> no_texture -> addr);
    if (i == 3)
       my_mlx_addr(map->so_texture, map -> so_texture -> addr);
    if (i == 4)
        my_mlx_addr(map->we_texture, map -> we_texture -> addr);
    if (i == 5)
         my_mlx_addr(map->ea_texture, map -> ea_texture -> addr);
	ft_printf("KOUKOU2\n");
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
	ft_printf("LA\n");
    while (i < 6)
    {
		ft_printf("LA1\n");
        way = ft_strdup(way_texture(data -> texture_color, CARAC_MAP[i]));
		ft_printf("LA2\n");
        if (set_texture(way, map, i) == 0)
            return (ft_error_texture("Error\nCan't set texture\n", data, map, i));
		ft_printf("LA END\n");
        i++;
    }
}
