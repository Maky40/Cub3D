#include "../include/cub3d.h"

float get_h_inter(t_map *map, float angl) // get the horizontal intersection
{
    float h_x;
    float h_y;
    float x_step;
    float y_step;
    int  pixel;

    y_step = CUBE_SIZE;
    x_step = CUBE_SIZE / tan(angl);
    h_y = floor(map->player->plyr_y / CUBE_SIZE) * CUBE_SIZE;
    pixel = inter_check(angl, &h_y, &y_step, 1);
    h_x = map->player->plyr_x + (h_y - map->player->plyr_y) / tan(angl);
    if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
    x_step *= -1;
    while (wall_hit(h_x, h_y - pixel, map)) // check the wall hit whit the pixel value
    {
    h_x += x_step;
    h_y += y_step;
    }
    return (sqrt(pow(h_x - map->player->plyr_x, 2) + pow(h_y - map->player->plyr_y, 2))); // get the distance
    }

    float get_v_inter(t_map *map, float angl) // get the vertical intersection
    {
    float v_x;
    float v_y;
    float x_step;
    float y_step;
    int  pixel;

    x_step = CUBE_SIZE; 
    y_step = CUBE_SIZE * tan(angl);
    v_x = floor(map->player->plyr_x / CUBE_SIZE) * CUBE_SIZE;
    pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
    v_y = map->player->plyr_y + (v_x - map->player->plyr_x) * tan(angl);
    if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
    y_step *= -1;
    while (wall_hit(v_x - pixel, v_y, map)) // check the wall hit whit the pixel value
    {
    v_x += x_step;
    v_y += y_step;
    }
    return (sqrt(pow(v_x - map->player->plyr_x, 2) + pow(v_y - map->player->plyr_y, 2))); // get the distance
    }