/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   my_hooks.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/05/05 19:55:28 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 14:58:29 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*mapdata;

	mapdata = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.action == MLX_RELEASE)
			return ;
		if (keydata.key == MLX_KEY_W)
			move_input(mapdata, 0, -1);
		if (keydata.key == MLX_KEY_S)
			move_input(mapdata, 0, 1);
		if (keydata.key == MLX_KEY_A)
			move_input(mapdata, -1, 0);
		if (keydata.key == MLX_KEY_D)
			move_input(mapdata, 1, 0);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		cleanup_all_resources(mapdata);
		exit (EXIT_SUCCESS);
	}
}

void	my_loophook(void *param)
{
	t_data	*mapdata;

	mapdata = param;
	if (mapdata->finished == 1)
	{
		cleanup_all_resources(mapdata);
		exit(EXIT_SUCCESS);
	}
}

void	cleanup_all_resources(t_data *mapdata)
{
	free_images(mapdata);
	free_textures(mapdata);
	if (mapdata->map)
		free_array(mapdata->map);
	if (mapdata->window)
		mlx_terminate(mapdata->window);
	if (mapdata->finished)
		ft_putstr_fd("You're the winning gnome!\n", STDOUT_FILENO);
	ft_putstr_fd("Closing window_____\n", STDOUT_FILENO);
}

void	print_moves(int moves)
{
	ft_putstr_fd("Updating map\nCurrent number of moves: ", STDOUT_FILENO);
	ft_putnbr_fd(moves, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
