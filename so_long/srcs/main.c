/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 15:42:56 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:50:20 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	main(int argc, char **argv)
{
	t_data	mapdata;

	ft_memset(&mapdata, 0, sizeof(t_data));
	mapdata.finished = 0;
	mapdata.gate_open = 0;
	mapdata.nbr_moves = 0;
	mapdata.path_check = 0;
	initialize_map(argc, &argv[1], &mapdata);
	mapdata.window = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mapdata.window)
		error_exit("Error\nFailed to create window\n", &mapdata);
	build_run_map(&mapdata, mapdata.window);
	return (0);
}
