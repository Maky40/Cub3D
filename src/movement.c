#include "../include/cub3d.h"

void	ft_moves_ws(t_data *data)
{
	if (data->moves.move_forward == 1)
	{
		if (data->map[(int)(data->y + (data->dir_y
					* data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y += data->dir_y * data->moves.move_speed;
		if (data->map[(int)(data->y)][(int)(data->x +
					(data->dir_x * data->moves.move_speed * 2))] == '0')
			data->x += data->dir_x * data->moves.move_speed;
	}
	if (data->moves.move_back == 1)
	{
		if (data->map[(int)(data->y - (data->dir_y
					* data->moves.move_speed * 2))][(int)(data->x)] == '0')
			data->y -= data->dir_y * data->moves.move_speed;
		if (data->map[(int)(data->y)][(int)(data->x -
					(data->dir_x * data->moves.move_speed * 2))] == '0')
			data->x -= data->dir_x * data->moves.move_speed;
	}
}

void	ft_moves_ad(t_data *data)
{
	if (data->moves.step_to_right == 1)
	{
		if (data->map[(int)(data->y + data->dir_x
				* (data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y += data->dir_x * data->moves.move_speed;
		if (data->map[(int)data->y][(int)(data->x
			- data->dir_y * (data->moves.move_speed * 2))] == '0')
			data->x -= data->dir_y * data->moves.move_speed;
	}
	if (data->moves.step_to_left == 1)
	{
		if (data->map[(int)(data->y - data->dir_x
				* (data->moves.move_speed * 2))][(int)data->x] == '0')
			data->y -= data->dir_x * data->moves.move_speed;
		if (data->map[(int)data->y][(int)(data->x
			+ data->dir_y * (data->moves.move_speed * 2))] == '0')
			data->x += data->dir_y * data->moves.move_speed;
	}
}

void	ft_rotate2(t_data *data)
{
	double	old_planx;
	double	old_dirx;

	old_planx = data->plan_x;
	old_dirx = data->dir_x;
	if (data->moves.rotate_right == 1)
	{
		data->dir_x = data->dir_x * cos(data->moves.rotate_speed)
			- data->dir_y * sin(data->moves.rotate_speed);
		data->dir_y = old_dirx * sin(data->moves.rotate_speed)
			+ data->dir_y * cos(data->moves.rotate_speed);
		data->plan_x = data->plan_x * cos(data->moves.rotate_speed)
			- data->plan_y * sin(data->moves.rotate_speed);
		data->plan_y = old_planx * sin(data->moves.rotate_speed)
			+ data->plan_y * cos(data->moves.rotate_speed);
	}
}
void	ft_rotate1(t_data *data)
{
	double	old_planx;
	double	old_dirx;

	old_planx = data->plan_x;
	old_dirx = data->dir_x;
	if (data->moves.rotate_left == 1)
	{
		data->dir_x = data->dir_x * cos(-data->moves.rotate_speed)
			- data->dir_y * sin(-data->moves.rotate_speed);
		data->dir_y = old_dirx * sin(-data->moves.rotate_speed)
			+ data->dir_y * cos(-data->moves.rotate_speed);
		data->plan_x = data->plan_x * cos(-data->moves.rotate_speed)
			- data->plan_y * sin(-data->moves.rotate_speed);
		data->plan_y = old_planx * sin(-data->moves.rotate_speed)
			+ data->plan_y * cos(-data->moves.rotate_speed);
	}
	else
		ft_rotate2(data);
}
