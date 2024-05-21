#include "../include/cub3d.h"

void	raycasting2(t_data *data)
{
	if (data->ray.ray_diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.side_disty = (data->y - data->ray.mapy)
			* data->ray.delta_disty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.side_disty = (data->ray.mapy + 1.0 - data->y)
			* data->ray.delta_disty;
	}
	raycasting_hit(data);
}

void	raycasting_hit(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_distx < data->ray.side_disty)
		{
			data->ray.side_distx += data->ray.delta_distx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_disty += data->ray.delta_disty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}

}

void	raycasting3(t_data *data)
{
	if (data->ray.side == 0)
	{
		data->ray.perp_wall_dist = (data->ray.side_distx
				- data->ray.delta_distx);
	}
	else
	{
		data->ray.perp_wall_dist = (data->ray.side_disty
				- data->ray.delta_disty);
	}
	if (data->ray.perp_wall_dist)
		data->ray.line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
	else
		data->ray.line_height = (int)(HEIGHT / 0.5);
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
}

void	raycasting4(t_data *data)
{
	if (data->ray.side == 0)
		data->texture.wall_x = data->y + data->ray.perp_wall_dist
			* data->ray.ray_diry;
	else
		data->texture.wall_x = data->x + data->ray.perp_wall_dist
			* data->ray.ray_dirx;
	data->texture.wall_x -= floor(data->texture.wall_x);
	if (data->ray.side == 1 && data->ray.mapy >= data->y)
	{
		data->texture.n_text = 1;
		data->texture.step = 1.0 * data->img_so.height / data->ray.line_height;
		data->texture.tex_x = (int)(data->texture.wall_x * data->img_so.width);
	}
	else if (data->ray.side == 1 && data->ray.mapy < data->y)
	{
		data->texture.n_text = 0;
		data->texture.step = 1.0 * data->img_n.height / data->ray.line_height;
		data->texture.tex_x = (int)(data->texture.wall_x * data->img_n.width);
	}
}

void	raycasting5(t_data *data)
{
	if (data->ray.side == 0 && data->ray.mapx >= data->x)
	{
		data->texture.n_text = 2;
		data->texture.step = 1.0 * data->img_ea.height / data->ray.line_height;
		data->texture.tex_x = (int)(data->texture.wall_x * data->img_ea.width);
	}
	else if (data->ray.side == 0 && data->ray.mapx < data->x)
	{
		data->texture.n_text = 3;
		data->texture.step = 1.0 * data->img_we.height / data->ray.line_height;
		data->texture.tex_x = (int)(data->texture.wall_x * data->img_we.width);
	}
}
