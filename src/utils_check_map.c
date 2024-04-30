#include "../include/cub3d.h"

void	free_map_duplicate(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}

char	**duplicate_map(char **map1)
{
	int		i;
	char	**map2;

	i = 0;
	while (map1[i])
		i++;
	map2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map1[i])
	{
		map2[i] = ft_strdup(map1[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

int	error_map(t_data *data)
{
	ft_printf("Map Error\n");
	free_map(data -> map);
	return (1);
}

// verify if char c is a correct character
int	check_char(char c)
{
	int	i;

	i = 0;
	while (CARAC_MAP[i])
	{
		if (CARAC_MAP[i] == c)
			return (0);
		i++;
	}
	return (1);
}