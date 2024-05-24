/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xav <xav@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:49:48 by xav               #+#    #+#             */
/*   Updated: 2024/05/24 10:58:47 by xav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_dir(t_data *data)
{
	if (data->start_player == 'N')
		data->dir_y = -1;
	if (data->start_player == 'S')
		data->dir_y = 1;
	if (data->start_player == 'E')
		data->dir_x = 1;
	if (data->start_player == 'W')
		data->dir_x = -1;
	if (data->start_player == 'N')
		data->plan_x = 0.66;
	if (data->start_player == 'S')
		data->plan_x = -0.66;
	if (data->start_player == 'E')
		data->plan_y = 0.66;
	if (data->start_player == 'W')
		data->plan_y = -0.66;
}

void	init_ray(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = 0;
	data->plan_x = 0;
	data->plan_y = 0;
	data->rx = 0;
	data->ry = 0;
	data->moves.move_forward = 0;
	data->moves.move_back = 0;
	data->moves.step_to_left = 0;
	data->moves.step_to_right = 0;
	data->moves.rotate_right = 0;
	data->moves.rotate_left = 0;
	data->moves.move_speed = 0.1;
	data->moves.rotate_speed = 0.1;
	init_dir(data);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (keysym == 119)
		data->moves.move_forward = 1;
	if (keysym == 97)
		data->moves.step_to_left = 1;
	if (keysym == 115)
		data->moves.move_back = 1;
	if (keysym == 100)
		data->moves.step_to_right = 1;
	if (keysym == 65361)
		data->moves.rotate_left = 1;
	if (keysym == 65363)
		data->moves.rotate_right = 1;
	return (1);
}

int	handle_input_release(int keysym, t_data *data)
{
	if (keysym == 119)
		data->moves.move_forward = 0;
	else if (keysym == 97)
		data->moves.step_to_left = 0;
	else if (keysym == 115)
		data->moves.move_back = 0;
	else if (keysym == 100)
		data->moves.step_to_right = 0;
	else if (keysym == 65361)
		data->moves.rotate_left = 0;
	else if (keysym == 65363)
		data->moves.rotate_right = 0;
	return (1);
}
