#include "../include/cub3d.h"

void	img_init(t_data *data)
{
	data->img_n.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->no_p, &data->img_n.width, &data->img_n.height);
	data->img_n.addr = mlx_get_data_addr(data->img_n.mlx_img,
			&data->img_n.bpp, &data->img_n.line_len, &data->img_n.endian);
	data->img_so.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->so_p, &data->img_so.width, &data->img_so.height);
	data->img_so.addr = mlx_get_data_addr(data->img_so.mlx_img,
			&data->img_so.bpp, &data->img_so.line_len, &data->img_so.endian);
	data->img_ea.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->ea_p, &data->img_ea.width, &data->img_ea.height);
	data->img_ea.addr = mlx_get_data_addr(data->img_ea.mlx_img,
			&data->img_ea.bpp, &data->img_ea.line_len, &data->img_ea.endian);
	data->img_we.mlx_img = mlx_xpm_file_to_image(data->mlx,
			data->we_p, &data->img_we.width, &data->img_we.height);
	data->img_we.addr = mlx_get_data_addr(data->img_we.mlx_img,
			&data->img_we.bpp, &data->img_we.line_len, &data->img_we.endian);
}

void	texture_choice(t_data *data)
{
	if (data->texture.n_text == 0)
	{
		data->texture.tex_y = (int)data->texture.tex_pos
			& (data->img_n.height - 1);
		data->texture.tex_pos += data->texture.step;
		data->texture.color = ((int *)data->img_n.addr)[data->texture.tex_x
			+ (data->texture.tex_y * data->img_n.line_len / sizeof(int))];
	}
	if (data->texture.n_text == 1)
	{
		data->texture.tex_y = (int)data->texture.tex_pos
			& (data->img_so.height - 1);
		data->texture.tex_pos += data->texture.step;
		data->texture.color = ((int *)data->img_so.addr)[data->texture.tex_x
			+ (data->texture.tex_y * data->img_so.line_len / sizeof(int))];
	}
	texture_choice2(data);
}

void	texture_choice2(t_data *data)
{
	if (data->texture.n_text == 2)
	{
		data->texture.tex_y = (int)data->texture.tex_pos
			& (data->img_ea.height - 1);
		data->texture.tex_pos += data->texture.step;
		data->texture.color = ((int *)data->img_ea.addr)[data->texture.tex_x
			+ (data->texture.tex_y * data->img_ea.line_len / sizeof(int))];
	}
	if (data->texture.n_text == 3)
	{
		data->texture.tex_y = (int)data->texture.tex_pos
			& (data->img_we.height - 1);
		data->texture.tex_pos += data->texture.step;
		data->texture.color = ((int *)data->img_we.addr)[data->texture.tex_x
			+ (data->texture.tex_y * data->img_we.line_len / sizeof(int))];
	}
}

void	raycasting1(t_data *data)
{
	data->ray.camerax = 2 * data->ray.var_x / (double)WIDTH - 1;
	data->ray.ray_dirx = data->dir_x + data->plan_x * data->ray.camerax;
	data->ray.ray_diry = data->dir_y + data->plan_y * data->ray.camerax;
	data->ray.mapx = (int)data->x;
	data->ray.mapy = (int)data->y;
	data->ray.delta_distx = fabs(1 / data->ray.ray_dirx);
	data->ray.delta_disty = fabs(1 / data->ray.ray_diry);
	data->ray.hit = 0;
	if (data->ray.ray_dirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.side_distx = (data->x - data->ray.mapx)
			* data->ray.delta_distx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.side_distx = (data->ray.mapx + 1.0 - data->x)
			* data->ray.delta_distx;
	}
}
