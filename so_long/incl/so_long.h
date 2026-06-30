/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   so_long.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 15:44:05 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:42:57 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/incl/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 4000
# define HEIGHT 1800

typedef struct s_data
{
	mlx_texture_t	*grass_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*pillar_t;
	mlx_texture_t	*gnome_t;
	mlx_texture_t	*flower_t;
	mlx_texture_t	*d_c_t;
	mlx_texture_t	*d_o_t;
	mlx_image_t		*grass_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*pillar_i;
	mlx_image_t		*gnome_i;
	mlx_image_t		*flower_i;
	mlx_image_t		*d_c_i;
	mlx_image_t		*d_o_i;
	char			**map;
	int				mapwidth;
	int				mapheight;
	int				s;
	int				ex;
	int				ey;
	int				px;
	int				py;
	int				c_count;
	int				path_check;
	int				nbr_moves;
	mlx_t			*window;
	mlx_texture_t	*texture;
	int				gate_open;
	int				finished;
}	t_data;

void		free_array(char **array);
void		error_exit(char *str, t_data *mapdata);
void		initialize_map(int argc, char **argv_map, t_data *mapdata);
void		check_map_elem(char **map, t_data *mapdata);
void		check_all_symbols(char **map, t_data *mapdata);
void		search_p(char **map, t_data *mapdata);
void		search_e(char **map, t_data *mapdata);
void		restore_map(t_data *mapdata);
void		last_check_path(char **map, t_data *mapdata);
void		loading_png(t_data *mapdata);
void		fetching_images(t_data *mapdata);
void		free_images(t_data *mapdata);
void		build_run_map(t_data *mapdata, mlx_t *window);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_loophook(void *param);
mlx_image_t	*png_to_mlx(t_data *mapdata, mlx_texture_t *texture, float adj);
void		my_mlx_pitw(t_data *mapdata, mlx_image_t *image, int x, int y);
void		update_background(t_data *mapdata, int x, int y);
void		update_player(t_data *mapdata);
void		update_exit(t_data *mapdata);
void		move_input(t_data *mapdata, int mx, int my);
void		remove_nl(t_data *mapdata);
void		count_lines(char **argv_map, t_data *mapdata);
void		cleanup_all_resources(t_data *mapdata);
void		print_moves(int moves);
void		free_textures(t_data *mapdata);
void		exit_stays(t_data *mapdata);
#endif
