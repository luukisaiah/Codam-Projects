/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   update_map.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/05/05 16:33:22 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:51:56 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	update_background(t_data *mapdata, int x, int y)
{
	mlx_image_t	*new_grass;

	new_grass = png_to_mlx(mapdata, mapdata->grass_t, 1);
	if (!new_grass)
		error_exit("Error\nPNG to mlx failed.\n", mapdata);
	if (!mlx_resize_image(new_grass, mapdata->s, mapdata->s))
		error_exit("Error\nresizing image failed\n", mapdata);
	if (mlx_image_to_window(mapdata->window, new_grass, x * mapdata->s,
			y * mapdata->s) < 0)
		error_exit("Error\nImage_to_window failed\n", mapdata);
}

void	update_player(t_data *mapdata)
{
	mlx_image_t	*new_gnome;

	new_gnome = png_to_mlx(mapdata, mapdata->gnome_t, 1);
	if (!new_gnome)
		error_exit("Error\nPNG to MLX failed\n", mapdata);
	if (!mlx_resize_image(new_gnome, mapdata->s, mapdata->s))
		error_exit("Error\nresizing image failed\n", mapdata);
	if (mlx_image_to_window(mapdata->window, new_gnome,
			mapdata->px * mapdata->s, mapdata->py * mapdata->s) < 0)
		error_exit("Error\nImage_to_window fail\n", mapdata);
}

void	exit_stays(t_data *mapdata)
{
	mlx_image_t	*new_door;

	new_door = png_to_mlx(mapdata, mapdata->d_c_t, 1);
	if (!new_door)
		error_exit("Error\nPNG to MLX failed\n", mapdata);
	if (!mlx_resize_image(new_door, mapdata->s, mapdata->s))
		error_exit("Error\nresizing image failed\n", mapdata);
	if (mlx_image_to_window(mapdata->window, new_door,
			mapdata->ex * mapdata->s, mapdata->ey * mapdata->s) < 0)
		error_exit("Error\nImage_to_window fail\n", mapdata);
}

void	update_exit(t_data *mapdata)
{
	mlx_image_t	*new_door;

	mapdata->gate_open = 1;
	new_door = png_to_mlx(mapdata, mapdata->d_o_t, 1);
	if (!new_door)
		error_exit("Error\nPNG to MLX failed\n", mapdata);
	if (!mlx_resize_image(new_door, mapdata->s, mapdata->s))
		error_exit("Error\nresizing image failed\n", mapdata);
	if (mlx_image_to_window(mapdata->window, new_door,
			mapdata->ex * mapdata->s, mapdata->ey * mapdata->s) < 0)
		error_exit("Error\nImage_to_window fail\n", mapdata);
}

void	count_lines(char **argv_map, t_data *mapdata)
{
	char	*str;
	int		fd;
	int		count;

	count = 0;
	fd = open(*argv_map, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nCan't read/open map\n", NULL);
	str = get_next_line(fd);
	if (!str)
		error_exit("Error\nget_next_line failed\n", NULL);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	mapdata->mapheight = count;
	close(fd);
}
