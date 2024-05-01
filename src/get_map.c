#include "../include/cub3d.h"

char	*get_map(int fd)
{
	char	*line;
	char	*all_line;

	all_line = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		all_line = ft_strjoin(all_line, line);
		free (line);
		line = get_next_line(fd);
	}
	return (all_line);
}

char	**parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data -> map = ft_split(get_map(fd), '\n');
	if (!data -> map)
	{
		ft_error("Error\nFichier vide");
		return (data -> map);
	}
}
char    *get_texture_color(int fd)
{
    char    *line;
    char    *all_line;
    int     i;
    int     j;

    i = 0;
    j = 0;
    all_line = get_next_line(fd);
    line = get_next_line(fd);
    while (line[i] == ' ')
        i++;
    while (all_line[j] == ' ')
        j++;
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
     return (all_line);    
}
void    parse_data(t_data *data, int fd)
{
    int i;

    i = 0;
    data -> texture_color = ft_split(get_texture_color(fd), '\n');
    while (data -> texture_color[i])
    {
        // check if the texture / color exist
        i++;
    }
    if (i != 6)
    {
        return (ft_error_texture("Error\nNo all texture or color", data));
        // create function for free data -> texture_color
    }
}

t_data	*init_data(char **str, t_data *data)
{
	int	fd;

	fd = 0;
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
	}
	return (data);
}
