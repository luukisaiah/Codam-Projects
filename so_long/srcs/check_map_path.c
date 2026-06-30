/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_map_path.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 19:05:07 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:51:09 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_all_symbols(char **map, t_data *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P' ||
				map[i][j] == '1' || map[i][j] == '0' || map[i][j] == '\n')
				j++;
			else
				error_exit("Error\nIlligal symbols found\n", mapdata);
		}
		i++;
	}
}

void	search_p(char **map, t_data *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				mapdata->px = j;
				mapdata->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
	if (map[i] == NULL)
		error_exit("Error\nNo player found\n", mapdata);
}

void	search_e(char **map, t_data *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				mapdata->ex = j;
				mapdata->ey = i;
				return ;
			}
			j++;
		}
		i++;
	}
	if (map[i] == NULL)
		error_exit("Error\nNo exit found\n", mapdata);
}

void static	flood_the_fill(int x, int y, char **map, t_data *mapdata)
{
	if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != 'E' &&
		map[y][x] != 'C')
		return ;
	if (map[y][x] == 'P')
		map[y][x] = 'p';
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'c';
	}
	else if (map[y][x] == '0')
		map[y][x] = 'o';
	else if (map[y][x] == 'E')
		map[y][x] = 'e';
	flood_the_fill(x - 1, y, map, mapdata);
	flood_the_fill(x + 1, y, map, mapdata);
	flood_the_fill(x, y - 1, map, mapdata);
	flood_the_fill(x, y + 1, map, mapdata);
}

void	last_check_path(char **map, t_data *mapdata)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = mapdata->px;
	y = mapdata->py;
	flood_the_fill(x, y, map, mapdata);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				error_exit("Error\nMap has no valid path\n", mapdata);
			j++;
		}
		i++;
	}
	restore_map(mapdata);
	mapdata->path_check = 1;
}
