/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   image_loading.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/05/05 13:04:21 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 12:28:44 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

mlx_image_t	*png_to_mlx(t_data *mapdata, mlx_texture_t *texture, float adj)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(mapdata->window, texture);
	if (!image)
		error_exit("Error\ntexture to image failed\n", mapdata);
	if (!mlx_resize_image(image, mapdata->s * adj, mapdata->s * adj))
		error_exit("Error\nresizing image failed\n", mapdata);
	return (image);
}

void	loading_png(t_data *mapdata)
{
	mapdata->grass_t = mlx_load_png("./images/Grass_middle.png");
	if (!mapdata->grass_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->wall_t = mlx_load_png("./images/Wood_outside.png");
	if (!mapdata->wall_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->pillar_t = mlx_load_png("./images/Slime_pillar.png");
	if (!mapdata->pillar_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->gnome_t = mlx_load_png("./images/Gnome.png");
	if (!mapdata->gnome_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->flower_t = mlx_load_png("./images/Flower.png");
	if (!mapdata->flower_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->d_c_t = mlx_load_png("./images/wooden_door_closed.png");
	if (!mapdata->d_c_t)
		error_exit("Error\nloading png\n", mapdata);
	mapdata->d_o_t = mlx_load_png("./images/wooden_door_open.png");
	if (!mapdata->d_o_t)
		error_exit("Error\nloading png\n", mapdata);
}

void	fetching_images(t_data *mapdata)
{
	mapdata->wall_i = png_to_mlx(mapdata, mapdata->wall_t, 1);
	if (!mapdata->wall_i)
		error_exit("Error\nloading image\n", mapdata);
	mapdata->pillar_i = png_to_mlx(mapdata, mapdata->pillar_t, 1);
	if (!mapdata->pillar_i)
		error_exit("Error\nloading image\n", mapdata);
	mapdata->gnome_i = png_to_mlx(mapdata, mapdata->gnome_t, 1);
	if (!mapdata->gnome_i)
		error_exit("Error\nloading image\n", mapdata);
	mapdata->flower_i = png_to_mlx(mapdata, mapdata->flower_t, 1);
	if (!mapdata->flower_i)
		error_exit("Error\nloading image\n", mapdata);
	mapdata->d_c_i = png_to_mlx(mapdata, mapdata->d_c_t, 1);
	if (!mapdata->d_c_i)
		error_exit("Error\nloading image\n", mapdata);
	mapdata->d_o_i = png_to_mlx(mapdata, mapdata->d_o_t, 1);
	if (!mapdata->d_o_i)
		error_exit("Error\nloading image\n", mapdata);
}

void	free_images(t_data *mapdata)
{
	if (!mapdata->window)
		return ;
	if (mapdata->grass_i)
		mlx_delete_image(mapdata->window, mapdata->grass_i);
	if (mapdata->wall_i)
		mlx_delete_image(mapdata->window, mapdata->wall_i);
	if (mapdata->pillar_i)
		mlx_delete_image(mapdata->window, mapdata->pillar_i);
	if (mapdata->gnome_i)
		mlx_delete_image(mapdata->window, mapdata->gnome_i);
	if (mapdata->flower_i)
		mlx_delete_image(mapdata->window, mapdata->flower_i);
	if (mapdata->d_c_i)
		mlx_delete_image(mapdata->window, mapdata->d_c_i);
	if (mapdata->d_o_i)
		mlx_delete_image(mapdata->window, mapdata->d_o_i);
}

void	free_textures(t_data *mapdata)
{
	if (mapdata->grass_t)
		mlx_delete_texture(mapdata->grass_t);
	if (mapdata->wall_t)
		mlx_delete_texture(mapdata->wall_t);
	if (mapdata->pillar_t)
		mlx_delete_texture(mapdata->pillar_t);
	if (mapdata->gnome_t)
		mlx_delete_texture(mapdata->gnome_t);
	if (mapdata->flower_t)
		mlx_delete_texture(mapdata->flower_t);
	if (mapdata->d_c_t)
		mlx_delete_texture(mapdata->d_c_t);
	if (mapdata->d_o_t)
		mlx_delete_texture(mapdata->d_o_t);
}
