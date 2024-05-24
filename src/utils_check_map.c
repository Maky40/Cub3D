/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:49:25 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 18:10:08 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**get_map(char **tab_line, int fd, t_data *data)
{
	char	*line;
	char	*all_line;
	int		i;
	char	**map;

	all_line = ft_strdup(tab_line[1]);
	line = get_next_line(fd);
	while (line)
	{
		all_line = ft_strjoin(all_line, line);
		free (line);
		line = get_next_line(fd);
	}
	free_tab_tab(tab_line);
	i = 0;
	while (all_line[i])
	{
		if (all_line[i] == '\n' && all_line[i + 1] == '\n')
			data -> valid_map = 0;
		i++;
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	return (map);
}

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
