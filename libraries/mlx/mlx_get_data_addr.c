/*
** mlx_get_data_addr.c for MiniLibX in raytraceur
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Mon Aug 14 15:45:57 2000 Charlie Root
** Last update Thu Sep 27 19:05:25 2001 Charlie Root
*/



#include	"mlx_int.h"
#include <stdio.h>


char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian)
{
	// printf("%p, %p, %p", bits_per_pixel, size_line, endian);
	bits_per_pixel = malloc(sizeof(int));
	size_line = malloc(sizeof(int));
	endian = malloc(sizeof(int));
	printf("LA\n");
  *bits_per_pixel = img->bpp;
  printf("LA1\n");
  *size_line = img->size_line;
  printf("LA2\n");
  *endian = img->image->byte_order;
  printf("LA3\n");
  return (img->data);
}
