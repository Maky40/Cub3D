/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:50:18 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 10:57:04 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_map(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	free_data_map(data);
	free_data_texture_color(data);
	data -> valid_map = 0;
}

void	ft_error_texture(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	data -> valid_texture_color = 0;
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
}

void	error_color(char *str, t_data *data, int fd)
{
	ft_printf("%s", str);
	free_data_texture_color(data);
	free_gnl(fd);
	data -> valid_texture_color = 0;
}
