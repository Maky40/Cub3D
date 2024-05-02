#include "../include/cub3d.h"

char	*get_map(char **tab_line, int fd, t_data *data)
{
	char	*line;
	char	*all_line;
	int		i;

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
	}
	return (all_line);
}

char	**return_tab_line(char *all_line, char *line)
{
	char	**tab_line;
	int		i;

	i = 0;
	while (all_line[i] == ' ')
		i++;
	tab_line = malloc(sizeof(char *) * 2 + 1);
	tab_line[0] = ft_strdup(all_line + i);
	tab_line[1] = ft_strdup(line);
	tab_line[2] = '\0';
	return (tab_line);
}

char	**get_texture_color(int fd)
{
	char	*line;
	char	*all_line;
	int		i;

	i = 0;
	all_line = get_next_line(fd);
	line = get_next_line(fd);
	while (line[i] == ' ')
		i++;
	while (line[i] == 'F' || line[i] == 'C' || (line[i] == 'N' && line[i + 1] == 'O') || \
	 (line[i] == 'S' && line[i + 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E') || \
	 (line[i] == 'E' && line[i + 1] == 'A') || line[i] == '\n')
	 {
		all_line = ft_strjoin(all_line, line + i);
		free (line);
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
	data -> valid_texture_color = 1;
	tab_line = get_texture_color(fd);
	data -> texture_color = ft_split(tab_line[0], '\n');
	if (i != 6)
		return (ft_error_texture("Error\nNo all texture or color", data, tab_line));
	// init_texture(data -> texture_color); create verif and initialisation texture (verifier si toutes les textures sont bonnes. si pas bon set data -> valid color a 0 sinon a 1)
	if (data -> valid_texture_color == 0)
		return (ft_error_texture("Error\nTexture or color false", data, tab_line));
	data -> map = ft_split(get_map(tab_line, fd, data), '\n');
	free_tab_tab(tab_line);
	if (data -> valid_map == 0 || check_map(data) == 0)
		error_map("Error\nMap not closed or invalid char", data);
}

int	init_data(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data -> count_letter = 0;
	if (ft_strchr(str[1], ".cub") == 0)
	{
		ft_error("ERROR\n NEED EXTENSION .CUB FOR MAP (trouduc)\n");
		return (NULL);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_error("ERROR\n FAILED TO OPEN FILE\n");
			return (NULL);
		}
		parse_data(data, fd);
		if (data -> valid_texture_color == 0 || data -> valid_map == 0)
			return (0);
	}
	return (1);
}
