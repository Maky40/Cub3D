#include "../include/cub3d.h"

// verify if the side characters (crosses) and the characters in the corners of the square are correct (check_cross_angle)
void	check_cross_angle(char **cpy_map, int i, int j, t_data *data)
{
	if (cpy_map[i - 1][j] == ' ' || cpy_map[i + 1][j] == ' ')
		data -> valid_map = 0;
	if (cpy_map[i][j - 1] == ' ' || cpy_map[i][j + 1] == ' ')
		data -> valid_map = 0;
	if (cpy_map[i - 1][j - 1] == ' ' || (cpy_map[i - 1][j + 1] == 0 && \
	cpy_map[i - 1][j] != 0 && cpy_map[i][j - 1] != 0))
		data -> valid_map = 0;
	if (cpy_map[i + 1][j + 1] == ' ' || (cpy_map[i + 1][j + 1] == 0 && \
	cpy_map[i + 1][j] != 0 && cpy_map[i][j + 1] != 0))
		data -> valid_map = 0;
	if (cpy_map[i - 1][j + 1] == ' ' || (cpy_map[i - 1][j + 1] == 0 && \
	cpy_map[i - 1][j] != 0 && cpy_map[i][j + 1] != 0))
		data -> valid_map = 0;
	if (cpy_map[i + 1][j - 1] == ' ' || (cpy_map[i + 1][j - 1] == 0 && \
	cpy_map[i + 1][j] != 0 && cpy_map[i][j - 1] != 0))
		data -> valid_map = 0;
}

// verify if the character is surrounded by other characters with a squared shape around it
int	check_in_map(char **map, int i, int j)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (j == 0 || j == (int)ft_strlen(map[i]) - 1 || i == 0 || i == height - 1)
		return (1);
	if (j + 1 > (int)ft_strlen(map[i - 1]) - 1 ||  j + 1 > (int)ft_strlen(map[i + 1]) - 1)
		return (1);
	return (0);
}

// verify if the char is '0' (for the recursivity)
// verify if the character is surrounded by other characters with a squared shape around it (check_in_map)
// verify if the side characters (crosses) and the characters in the corners of the square are correct (check_cross_angle)
void	is_closed(char **cpy_map, int i, int j, t_data *data)
{
	if (cpy_map[i][j] != '0')
		return ;
	if (check_in_map(cpy_map, i, j) == 1)
	{
		data -> valid_map = 0;
		return ;
	}
	cpy_map[i][j] = '1';
	check_cross_angle(cpy_map, i, j, data);
	is_closed(cpy_map, i - 1, j, data);
	is_closed(cpy_map, i + 1, j, data);
	is_closed(cpy_map, i, j - 1, data);
	is_closed(cpy_map, i, j + 1, data);
}

// Duplicate the map, when find a '0' call the function is_closed
void	check_map_closed(t_data *data)
{
	char	**cpy_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy_map = duplicate_map(data -> map);
	while (cpy_map[i])
	{
		while (cpy_map[i][j])
		{
			if (cpy_map[i][j] == '0')
				is_closed(cpy_map, i, j, data);
			if (data -> valid_map == 0)
			{
				free_tab_tab(cpy_map);
				return ;
			}
			j++;
		}
		i++;
	}
	free_tab_tab(cpy_map);
	return ;
}
// The while loop check if we have only available characters (check_char function).
// Call the check_map function to find out whether map is closed or not.
// If the map is closed data -> valid = 0 else data -> valid = 1.
int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data -> map[i])
	{
		while (data -> map[i][j])
		{
			if (data -> map[i][j] == ' ')
				j++;
			if (check_char(data -> map[i][j], data) == 1 || data -> count_letter != 1)
				return (0);
			j++;
		}
		i++;
	}
	data -> valid_map = 1;
	check_map_closed(data);
	if (data -> valid_map == 0)
		return (0);
	return (1);
}
