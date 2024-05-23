#include "../include/cub3d.h"

char	**duplicate_map(char **map1)
{
	int		i;
	int		j;
	char	**map2;

	i = 0;
	while (map1[i])
		i++;
	map2 = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map1[++i])
		map2[i] = ft_strdup(map1[i]);
	map2[i] = NULL;
	i = -1;
	while (map2[++i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (ft_isalpha(map2[i][j]) == 1)
				map2[i][j] = '0';
			j++;
		}
	}
	return (map2);
}

char	**duplicate_map2(char **map1)
{
	int		i;
	char	**map2;

	i = 0;
	while (map1[i])
		i++;
	map2 = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map1[++i])
		map2[i] = ft_strdup(map1[i]);
	map2[i] = NULL;
	return (map2);
}
// verify if char c is a correct character and if there is only one char
int	check_char(char c, t_data *data)
{
	int	i;

	i = 0;
	while (CARAC_MAP[i])
	{
		if (c == ' ' || (c >= 7 && c <= 13))
			return (0);
		if (CARAC_MAP[i] == c)
		{
			if (ft_isalpha(c) == 1)
				data -> count_letter += 1;
			return (0);
		}
		i++;
	}
	return (1);
}