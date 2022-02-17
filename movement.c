/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:40:59 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/17 21:20:41 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(int x, int y, t_vars *vars)
{
	vars->x = x;
	vars->y = y;
}

void	ft_opendagates(t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->map[j][i] == 'E')
			{
				ft_draw_tile(vars, i, j, "./sprites/door_open.xpm");
			}
		}
	}
}

void	ft_checkmove(int keycode, t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == 'C')
	{	
		vars->map[vars->y][vars->x] = '0';
		vars->apple -= 1;
		if (vars->apple == 0)
			ft_opendagates(vars);
	}
	else if (keycode == 13 && (vars->map[vars->y][vars->x] == '1' || \
				(vars->map[vars->y][vars->x] == 'E' && ft_exit(vars) \
				== 0)))
		vars->y += 1;
	else if (keycode == 1 && (vars->map[vars->y][vars->x] == '1' || \
				(vars->map[vars->y][vars->x] == 'E' && ft_exit(vars) \
				== 0)))
		vars->y -= 1;
	else if (keycode == 0 && (vars->map[vars->y][vars->x] == '1' || \
				(vars->map[vars->y][vars->x] == 'E' && ft_exit(vars) \
				== 0)))
		vars->x += 1;
	else if (keycode == 2 && (vars->map[vars->y][vars->x] == '1' || \
				(vars->map[vars->y][vars->x] == 'E' && ft_exit(vars) \
				== 0)))
		vars->x -= 1;
}

void	ft_move(int keycode, t_vars *vars)
{
	ft_draw_tile(vars, vars->x, vars->y, "./sprites/floor_tile.xpm");
	if (keycode == 0)
	{	
		vars->x -= 1;
		ft_checkmove(keycode, vars);
		ft_draw_tile(vars, vars->x, vars->y, "./sprites/snekLeft.xpm");
	}
	else if (keycode == 2)
	{	
		vars->x += 1;
		ft_checkmove(keycode, vars);
		ft_draw_tile(vars, vars->x, vars->y, "./sprites/snekRight.xpm");
	}
	else if (keycode == 13)
	{
		vars->y -= 1;
		ft_checkmove(keycode, vars);
		ft_draw_tile(vars, vars->x, vars->y, "./sprites/snekUp.xpm");
	}
	else if (keycode == 1)
	{
		vars->y += 1;
		ft_checkmove(keycode, vars);
		ft_draw_tile(vars, vars->x, vars->y, "./sprites/snekDown.xpm");
	}
}
