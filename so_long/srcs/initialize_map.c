/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   initialize_map.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: lderks <lderks@codam.student.nl>              +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/28 18:49:47 by lderks         #+#    #+#                */
/*   Updated: 2025/05/08 16:43:36 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void static	input_check(int argc, char **argv_map)
{
	char	*str;
	int		len_ber;
	int		ber_comp;

	len_ber = 0;
	ber_comp = 0;
	str = ".ber";
	if (argc != 2 || !argv_map || !*argv_map)
		error_exit("Error\n./so_long map/<map>.ber\n", NULL);
	if (*argv_map)
	{
		len_ber = ft_strlen(*argv_map) - 4;
		if (len_ber <= 0)
			error_exit("Error\n./so_long map/<map>.ber\n", NULL);
		ber_comp = ft_strncmp(str, *argv_map + len_ber, 4);
	}
	if (ber_comp != 0)
		error_exit("Error\n./so_long map/<map>.ber\n", NULL);
	write(STDOUT_FILENO, "Checking the map_____\n", 22);
}

void static	get_next_map(char **argv_map, t_data *mapdata)
{
	char	*str_map;
	int		fd;
	int		i;

	i = 0;
	fd = open(*argv_map, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nCan't read/open map\n", NULL);
	str_map = get_next_line(fd);
	if (!str_map)
		error_exit("Error\nGet_next_line failed\n", NULL);
	while (str_map)
	{
		mapdata->map[i] = ft_strdup(str_map);
		if (!mapdata->map[i])
			error_exit("Error\nMalloc in ft_strdup failed\n", NULL);
		free(str_map);
		str_map = get_next_line(fd);
		i++;
	}
	free(str_map);
	mapdata->map[i] = NULL;
	close(fd);
}

void static	read_map(char **argv_map, t_data *mapdata)
{
	int		fd;
	int		i;

	count_lines(argv_map, mapdata);
	i = 0;
	fd = open(*argv_map, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nCan't read/open map\n", NULL);
	mapdata->map = (char **)malloc((mapdata->mapheight + 1) * sizeof(char *));
	if (mapdata->mapheight < 3)
		error_exit("Error\nMinimum of 3 vertical rows\n", mapdata);
	if (fd < 0 || !mapdata->map)
		error_exit("Error\nMalloc failed\n", NULL);
	get_next_map(argv_map, mapdata);
	close(fd);
}

void static	mapwidth_check(char **map, t_data *mapdata)
{
	int	i;
	int	len_c;
	int	len_next;

	i = 0;
	if (ft_strchr(map[0], '\n'))
		len_c = ft_strlen(map[0]) - 1;
	else
		len_c = ft_strlen(map[0]);
	mapdata->mapwidth = len_c;
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], '\n'))
			len_next = ft_strlen(map[i]) - 1;
		else
			len_next = ft_strlen(map[i]);
		if (len_c != len_next)
			error_exit("Error\nincosistent line length\n", mapdata);
		i++;
	}
}

void	initialize_map(int argc, char **argv_map, t_data *mapdata)
{
	input_check(argc, argv_map);
	read_map(argv_map, mapdata);
	if (!mapdata->map || !mapdata->map[0])
		error_exit("Error\nMap is NULL\n", NULL);
	remove_nl(mapdata);
	mapwidth_check(mapdata->map, mapdata);
	if (mapdata->mapwidth == mapdata->mapheight)
		error_exit("Error\nMap is not a rectangle\n", mapdata);
	check_map_elem(mapdata->map, mapdata);
	last_check_path(mapdata->map, mapdata);
	if (mapdata->path_check != 1)
		error_exit("Error\nMap has non valid path\n", mapdata);
}
