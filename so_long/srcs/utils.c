/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 18:41:52 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 11:33:21 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_exit(char *str, t_data *mapdata)
{
	int	len;

	len = ft_strlen(str);
	if (mapdata)
	{
		if (mapdata->map)
			free_array(mapdata->map);
		if (mapdata->window)
		{
			free_images(mapdata);
			mlx_terminate(mapdata->window);
		}
	}
	write(STDERR_FILENO, str, len);
	exit(EXIT_FAILURE);
}

void	remove_nl(t_data *mapdata)
{
	int	i;
	int	j;

	if (!mapdata || !mapdata->map)
		return ;
	i = 0;
	while (mapdata->map[i] != NULL)
	{
		j = 0;
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == '\n')
				mapdata->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	restore_map(t_data *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (mapdata->map[i])
	{
		j = 0;
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == 'c')
				mapdata->map[i][j] = 'C';
			else if (mapdata->map[i][j] == 'e')
				mapdata->map[i][j] = 'E';
			else if (mapdata->map[i][j] == 'p')
				mapdata->map[i][j] = 'P';
			else if (mapdata->map[i][j] == 'o')
				mapdata->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	my_mlx_pitw(t_data *mapdata, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(mapdata->window, image, x, y) < 0)
		error_exit("Error\nmlx_image_to_window failed\n", mapdata);
}
