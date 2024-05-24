/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:50:32 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 10:55:40 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	check_in_map(char **map, int i, int j)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (j == 0 || j == (int)ft_strlen(map[i]) - 1 || i == 0 || i == height - 1)
		return (1);
	if (j + 1 > (int)ft_strlen(map[i - 1])
		|| j + 1 > (int)ft_strlen(map[i + 1]))
		return (1);
	return (0);
}

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

void	check_map_closed(t_data *data)
{
	char	**cpy_map;
	int		i;
	int		j;

	i = 0;
	cpy_map = duplicate_map(data -> map);
	while (cpy_map[i])
	{
		j = 0;
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

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data -> count_letter = 0;
	while (data -> map[i])
	{
		j = 0;
		while (data -> map[i][j])
		{
			if (data -> map[i][j] == ' ')
				j++;
			if (check_char(data -> map[i][j], data) == 1)
				return (0);
			j++;
		}
		i++;
	}
	if (data -> count_letter != 1)
		return (0);
	data -> valid_map = 1;
	check_map_closed(data);
	if (data -> valid_map == 0)
		return (0);
	return (1);
}
