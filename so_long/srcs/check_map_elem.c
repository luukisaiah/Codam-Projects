/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_map_elem.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 18:53:43 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:45:58 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void static	check_pe(char **map, t_data *mapdata)
{
	int	count[2];
	int	i;
	int	j;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count[0]++;
			else if (map[i][j] == 'P')
				count[1]++;
			j++;
		}
		i++;
	}
	if (count[0] != 1)
		error_exit("Error\nInvalid amount of 'E'xits\n", mapdata);
	else if (count[1] != 1)
		error_exit("Error\nInvalid amount of 'P'layers\n", mapdata);
}

void static	check_c(char **map, t_data *mapdata)
{
	int	check_c;
	int	i;
	int	j;

	i = 0;
	check_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				check_c++;
			j++;
		}
		i++;
	}
	if (check_c <= 0)
		error_exit("Error\nNo (C) / collectable found\n", mapdata);
	mapdata->c_count = check_c;
}

void static	check_walls_hori(char **map, t_data *mapdata)
{
	int	i;

	i = 0;
	while (i < mapdata->mapwidth)
	{
		if (map[0][i] == '1')
			i++;
		else
			error_exit("Error\nMap not surrounded by walls\n", mapdata);
	}
	i = 0;
	while (i < mapdata->mapwidth)
	{
		if (map[mapdata->mapheight - 1][i] == '1')
			i++;
		else
			error_exit("Error\nMap not surrounded by walls\n", mapdata);
	}
}

void static	check_walls_vert(char **map, t_data *mapdata)
{
	int	i;

	i = 0;
	while (i < mapdata->mapheight)
	{
		if (map[i][0] == '1')
			i++;
		else
			error_exit("Error\nMap not surrounded by walls\n", mapdata);
	}
	i = 0;
	while (i < mapdata->mapheight)
	{
		if (map[i][mapdata->mapwidth - 1] == '1')
			i++;
		else
			error_exit("Error\nMap not surrounded by walls\n", mapdata);
	}
}

void	check_map_elem(char **map, t_data *mapdata)
{
	check_all_symbols(map, mapdata);
	check_pe(map, mapdata);
	check_c(map, mapdata);
	check_walls_hori(map, mapdata);
	check_walls_vert(map, mapdata);
	search_p(map, mapdata);
	search_e(map, mapdata);
}
