/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:57 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 11:02:33 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_data_map(t_data *data)
{
	free_tab_tab(data -> map);
	data -> map = NULL;
	return ;
}

void	free_data_texture_color(t_data *data)
{
	free_tab_tab(data -> texture_color);
	data -> texture_color = NULL;
	return ;
}
