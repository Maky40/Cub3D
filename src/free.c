/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:50:09 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 11:03:08 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tab_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	free_data(t_data *data)
{
	if (data->no_p)
		free(data->no_p);
	if (data->we_p)
		free(data->we_p);
	if (data->ea_p)
		free(data->ea_p);
	if (data->so_p)
		free(data->so_p);
	if (data -> texture_color)
		free_tab_tab(data -> texture_color);
	free_tab_tab(data->map);
	data->map = 0;
	free(data);
}

void	free_error(t_data *data, char *s)
{
	free_data(data);
	data->no_p = 0;
	data->we_p = 0;
	data->ea_p = 0;
	data->so_p = 0;
	ft_printf("%s", s);
}

int	ft_finish(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_image(data->mlx, data->img_ea.mlx_img);
	mlx_destroy_image(data->mlx, data->img_n.mlx_img);
	mlx_destroy_image(data->mlx, data->img_so.mlx_img);
	mlx_destroy_image(data->mlx, data->img_we.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
