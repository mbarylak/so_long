/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:38:01 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/25 17:26:52 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	*ft_get_info(char *file, t_vars *vars)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2, vars);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line && line[vars->width] != '\n')
		vars->width++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		vars->height++;
	}
	close(fd);
	if (vars->width <= 1 || vars->height <= 1)
		ft_error(0, vars);
	return (vars);
}

void	ft_make_map(char *file, t_vars *vars)
{
	int		h;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	h = vars->height;
	vars->map = malloc (sizeof (char *) * h);
	if (!vars->map)
		return ;
	i = 0;
	while (i < h)
	{
		vars->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	ft_draw_tile(t_vars *vars, size_t x, size_t y, char *imgname)
{
	void	*img;
	int		tile;
	size_t	i;
	size_t	j;

	tile = TILE;
	i = (tile * x);
	j = (tile * y);
	img = mlx_xpm_file_to_image(vars->mlx, imgname, &tile, &tile);
	mlx_put_image_to_window(vars->mlx, vars->win, img, i, j);
	mlx_destroy_image(vars->mlx, img);
}

void	ft_draw_map(char **map, t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (map[j][i] == '1')
				ft_draw_tile(vars, i, j, "sprites/wall_tile.xpm");
			if (map[j][i] == '0')
				ft_draw_tile(vars, i, j, "sprites/floor_tile.xpm");
			if (map[j][i] == 'P')
				ft_draw_tile(vars, i, j, "sprites/snekDown.xpm");
			if (map[j][i] == 'C')
				ft_draw_tile(vars, i, j, "sprites/apple.xpm");
			if (map[j][i] == 'E')
				ft_draw_tile(vars, i, j, "sprites/door_close.xpm");
		}
	}
}
