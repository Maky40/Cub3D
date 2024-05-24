/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:26:38 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 11:47:58 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	way_texture(char *tab)
{
	int		i;

	i = 2;
	while (tab[i] == ' ')
		i++;
	return (i);
}

int	check_name_texture(t_data *data)
{
	data -> ea_p = NULL;
	data -> no_p = NULL;
	data -> we_p = NULL;
	data -> so_p = NULL;
	if (data -> texture_color[1][0] != 'E'
	&& data -> texture_color[1][1] != 'A')
		return (0);
	else
		data -> ea_p = ft_strdup((data -> texture_color[1]
					+ way_texture(data -> texture_color[1])));
	if (data -> texture_color[3][0] != 'N'
		&& data -> texture_color[3][1] != 'O')
		return (0);
	else
		data -> no_p = ft_strdup((data -> texture_color[3]
					+ way_texture(data -> texture_color[3])));
	if (data -> texture_color[4][0] != 'S'
		&& data -> texture_color[4][1] != 'O')
		return (0);
	else
		data -> so_p = ft_strdup((data -> texture_color[4]
					+ way_texture(data -> texture_color[4])));
	if (data -> texture_color[5][0] != 'W'
		&& data -> texture_color[5][1] != 'E')
		return (0);
	else
		data -> we_p = ft_strdup((data -> texture_color[5]
					+ way_texture(data -> texture_color[5])));
	if (text_check(data) == 0)
		return (0);
	return (1);
}

void	delete_white_space(t_data *data, int i)
{
	char	*new;
	int		j;

	j = 0;
	while (data -> texture_color[i][j] == ' ')
		j++;
	new = ft_strdup(data -> texture_color[i] + j);
	free(data -> texture_color[i]);
	data -> texture_color[i] = new;
}

void	init_texture(t_data *data)
{
	int		i;
	char	*swap;

	i = 0;
	while (i < 6)
	{
		delete_white_space(data, i);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (ft_strncmp(data -> texture_color[i],
				data -> texture_color[i + 1], 1) > 0)
		{
			swap = data -> texture_color[i];
			data -> texture_color[i] = data -> texture_color[i + 1];
			data -> texture_color[i + 1] = swap;
			i = -1;
		}
		i++;
	}
	if (check_name_texture(data) == 0)
		return (ft_error_texture("Error\nCan't set texture\n", data));
}
