/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   build_map.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/05/03 13:02:02 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:45:29 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	build_floor(t_data *mapdata)
{
	int				i;
	int				j;

	i = 0;
	mapdata->grass_i = png_to_mlx(mapdata, mapdata->grass_t, 1);
	if (!mapdata->grass_i)
		error_exit("Error\nPNG to MLX failed\n", mapdata);
	if (!mlx_resize_image(mapdata->grass_i, mapdata->s, mapdata->s))
		error_exit("Error\nresizing image failed\n", mapdata);
	while (i < mapdata->mapheight)
	{
		j = 0;
		while (j < mapdata->mapwidth)
		{
			my_mlx_pitw(mapdata, mapdata->grass_i, j * mapdata->s,
				i * mapdata->s);
			j++;
		}
		i++;
	}
}

void	build_components(t_data *mapdata, int *i, int *j)
{
	while (mapdata->map[*i])
	{
		*j = 0;
		while (mapdata->map[*i][*j])
		{
			if (mapdata->map[*i][*j] == '1')
				my_mlx_pitw(mapdata, mapdata->wall_i, *j * mapdata->s,
					*i * mapdata->s);
			if (mapdata->map[*i][*j] == 'P')
				my_mlx_pitw(mapdata, mapdata->gnome_i, *j * mapdata->s,
					*i * mapdata->s);
			if (mapdata->map[*i][*j] == 'E')
				my_mlx_pitw(mapdata, mapdata->d_c_i, *j * mapdata->s,
					*i * mapdata->s);
			if (mapdata->map[*i][*j] == 'C')
				my_mlx_pitw(mapdata, mapdata->flower_i, *j * mapdata->s,
					*i * mapdata->s);
			(*j)++;
		}
		(*i)++;
	}
}

int	check_move(t_data *mapdata, int px, int py)
{
	if (mapdata->map[py][px] == '1')
	{
		ft_putstr_fd("Gnomes can't go trough walls\n", STDOUT_FILENO);
		return (1);
	}
	else if (mapdata->map[py][px] == 'C')
	{
		mapdata->map[py][px] = '0';
		mapdata->c_count = mapdata->c_count - 1;
		return (0);
	}
	else if (mapdata->map[py][px] == 'E')
	{
		if (mapdata->c_count != 0)
			ft_putstr_fd("CHOP all flowers before exit opens\n", STDOUT_FILENO);
		return (2);
	}
	return (0);
}

void	move_input(t_data *mapdata, int mx, int my)
{
	int	move_result;
	int	old_x;
	int	old_y;

	move_result = check_move(mapdata, mapdata->px + mx, mapdata->py + my);
	if (move_result == 1)
		return ;
	mapdata->nbr_moves++;
	print_moves(mapdata->nbr_moves);
	old_x = mapdata->px;
	old_y = mapdata->py;
	mapdata->px += mx;
	mapdata->py += my;
	if (mapdata->map[mapdata->py][mapdata->px] != 'E')
		mapdata->map[mapdata->py][mapdata->px] = 'P';
	if ((old_x == mapdata->ex && old_y == mapdata->ey) && mapdata->c_count != 0)
		exit_stays(mapdata);
	else
		update_background(mapdata, old_x, old_y);
	update_player(mapdata);
	if (mapdata->c_count == 0 && !mapdata->gate_open)
		update_exit(mapdata);
	if (move_result == 2 && mapdata->gate_open)
		mapdata->finished = 1;
}

void	build_run_map(t_data *mapdata, mlx_t *window)
{
	int	x_scale;
	int	y_scale;
	int	i;
	int	j;

	x_scale = WIDTH / (mapdata->mapwidth * 16) * (WIDTH / 100);
	y_scale = HEIGHT / (mapdata->mapheight * 16) * (HEIGHT / 100);
	i = 0;
	j = 0;
	if (x_scale > y_scale)
		mapdata->s = y_scale;
	else
		mapdata->s = x_scale;
	loading_png(mapdata);
	fetching_images(mapdata);
	mapdata->nbr_moves = 0;
	write(STDOUT_FILENO, "Opening window_____\n", 20);
	build_floor(mapdata);
	build_components(mapdata, &i, &j);
	mlx_key_hook(window, &my_keyhook, mapdata);
	mlx_loop_hook(window, &my_loophook, mapdata);
	mlx_loop(window);
	cleanup_all_resources(mapdata);
}
