
#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/gnl/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# define CARAC_MAP "10NSWE"

typedef struct data_s
{
	char	**map;
	int		valid_map;
	int		valid_texture_color;
	int		count_letter;
	char	**texture_color;
}				t_data;

// check map
int		check_map(t_data *data);
char	**duplicate_map(char **map1);
int		check_char(char c);
// free
void	free_data_map(t_data *data);
void	free_data_texture_color(t_data *data);
void	free_tab_tab(char **tab);
// errors
void		error_map(char *str, t_data *data);
void	ft_error_texture(char **str, t_data *data, char **tab);
#endif
