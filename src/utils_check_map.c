#include "../include/cub3d.h"

int	check_carac(char c)
{
	int	i;

	i = 0;
	while (CARAC_MAP[i])
	{
		if (CARAC_MAP[i] == c)
			return (0);
		i++;
	}
	return (1);
}