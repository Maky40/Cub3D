/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_texture2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:31:21 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 11:34:43 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_search(char *buffer, char *pixel)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		if (buffer[i] == pixel[j])
		{
			while (pixel[j] && buffer [i + j])
			{
				if (pixel[j] == buffer[j + i])
				{
					j++;
					if (!pixel[j])
						return (1);
				}
				else
					break ;
			}
		}
		i++;
	}
	return (0);
}

int	valid_file(char *way)
{
	int		fd;
	ssize_t	bytesread;
	char	buffer[1024];

	fd = open(way, O_RDONLY);
	if (fd < 0)
		return (0);
	bytesread = read(fd, buffer, sizeof(buffer) - 1);
	while (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		if (ft_search(buffer, "pixels") == 1)
			return (1);
		bytesread = read(fd, buffer, sizeof(buffer) - 1);
	}
	return (0);
}

int	text_check(t_data *data)
{
	if (valid_file(data->we_p) == 0)
		return (0);
	if (valid_file(data->so_p) == 0)
		return (0);
	if (valid_file(data->no_p) == 0)
		return (0);
	if (valid_file(data->ea_p) == 0)
		return (0);
	return (1);
}
