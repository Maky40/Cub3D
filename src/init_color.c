/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:49:54 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 10:58:08 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
		return (0);
	return (1);
}

int	set_color2(char **rgb)
{
	int	r;
	int	g;
	int	b;
	int	color;

	color = 0;
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_tab_tab(rgb);
	if (check_colors(r, g, b))
	{
		color = r;
		color = (color << 8) + g;
		color = (color << 8) + b;
	}
	else
		return (-1);
	return (color);
}

int	set_color(char **tab, char c)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == ' ')
			j++;
		if (tab[i][j] == c)
			break ;
		i++;
	}
	if (!tab[i])
		return (-1);
	rgb = ft_split(tab[i] + j + 1, ',');
	return (set_color2(rgb));
}

void	init_color(t_data *data, int fd)
{
	data -> color_cap = set_color(data -> texture_color, 'C');
	data -> color_floor = set_color(data -> texture_color, 'F');
	if (data -> color_cap == -1 || data -> color_floor == -1)
		return (error_color("Error\nColor Invalid", data, fd));
}
