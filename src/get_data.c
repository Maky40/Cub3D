/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:50:01 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 18:09:46 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**return_tab_line(char *all_line, char *line)
{
	char	**tab_line;
	int		i;

	i = 0;
	while (all_line[i] == ' ')
		i++;
	tab_line = malloc(sizeof(char *) * 3);
	tab_line[0] = ft_strdup(all_line + i);
	tab_line[1] = ft_strdup(line);
	tab_line[2] = NULL;
	free(all_line);
	free(line);
	return (tab_line);
}

char	**get_texture_color2(char *all_line, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line && (line[i] == 'F' || line[i] == 'C' \
	|| (line[i] == 'N' && line[i + 1] == 'O') || \
	(line[i] == 'S' && line[i + 1] == 'O') \
	|| (line[i] == 'W' && line[i + 1] == 'E') \
	|| (line[i] == 'E' && line[i + 1] == 'A') \
	|| line[i] == '\n'))
	{
		all_line = ft_strjoin(all_line, line + i);
		free(line);
		i = 0;
		line = get_next_line(fd);
		while (line[i] == ' ')
			i++;
	}
	return (return_tab_line(all_line, line));
}

char	**get_texture_color(int fd)
{
	char	*line;
	char	*all_line;
	int		i;

	i = 0;
	all_line = get_next_line(fd);
	if (!all_line)
		return (NULL);
	while (all_line[i] == ' ')
		i++;
	if (all_line[i] && (all_line[i] == 'F' || all_line[i] == 'C' \
	|| (all_line[i] == 'N' && all_line[i + 1] == 'O') || \
	(all_line[i] == 'S' && all_line[i + 1] == 'O') \
	|| (all_line[i] == 'W' && all_line[i + 1] == 'E') \
	|| (all_line[i] == 'E' && all_line[i + 1] == 'A') \
	|| all_line[i] == '\n'))
	{
		line = get_next_line(fd);
		if (line)
			return (get_texture_color2(all_line, line, fd));
	}
	free(all_line);
	free_gnl(fd);
	return (NULL);
}

void	parse_data(t_data *data, int fd)
{
	int		i;
	char	**tab_line;

	i = 0;
	tab_line = get_texture_color(fd);
	if (!tab_line)
	{
		ft_printf("Error\nFile empty or not enough texture / color");
		data -> valid_texture_color = 0;
		return ;
	}
	data -> texture_color = ft_split(tab_line[0], '\n');
	while (data -> texture_color[i])
		i++;
	if (i != 6)
		return (error_color("Error\nNo all texture or color", data, fd));
	init_color(data, fd);
	if (data -> valid_texture_color == 0)
	{
		free_tab_tab(tab_line);
		return ;
	}
	data -> map = get_map(tab_line, fd, data);
	if (check_map(data) == 0 || data -> valid_map == 0)
		error_map("Error\nMap not closed or invalid char", data);
}

int	init_data(char **str, t_data *data)
{
	int	fd;

	data -> valid_texture_color = 1;
	data -> valid_map = 1;
	fd = 0;
	data -> count_letter = 0;
	if (ft_strchr(str[1], ".cub") == 0)
	{
		ft_printf("ERROR\n NEED EXTENSION .CUB FOR MAP (trouduc)\n");
		return (0);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_printf("ERROR\n FAILED TO OPEN FILE\n");
			return (0);
		}
		parse_data(data, fd);
		if (data -> valid_texture_color == 0 || data -> valid_map == 0)
			return (0);
	}
	return (1);
}
