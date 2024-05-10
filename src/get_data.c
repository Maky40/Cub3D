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

char	**get_texture_color(int fd)
{
	char	*line;
	char	*all_line;
	int		i;

	i = 0;
	all_line = get_next_line(fd);
	if (!all_line)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		free(all_line);
		return (NULL);
	}
	while (line[i] == ' ')
		i++;
	while (line && (line[i] == 'F' || line[i] == 'C' \
	|| (line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i + 1] == 'O') \
	|| (line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A') \
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
		return (ft_error_texture("Error\nNo all texture or color", data, tab_line, fd));
	init_texture_color(data, fd);
	if (data -> valid_texture_color == 0)
	{
		free_tab_tab(tab_line);
		return ;
	}
	data -> map = get_map(tab_line, fd, data);
	if (data -> valid_map == 0 || check_map(data) == 0)
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
