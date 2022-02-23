/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:40:59 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/23 18:33:48 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(int x, int y, t_vars *vars)
{
	vars->x = x;
	vars->y = y;
	vars->snake->x = x;
	vars->snake->y = y;
	vars->snake->prev = NULL;
	vars->snake->next = NULL;
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

void	ft_move_snake(t_vars *vars)
{
	t_snake	*init;
	size_t	i;
	size_t	j;

	init = vars->snake;
	while (vars->snake != NULL)
	{
		if (vars->snake->prev != NULL)
			ft_swap(&vars->snake->x, &vars->snake->y, &i, &j);
		else
		{
			i = vars->snake->x;
			j = vars->snake->y;
		}
		vars->snake = vars->snake->next;
	}
	vars->snake = init;
	vars->snake->x = vars->x;
	vars->snake->y = vars->y;
}

void	ft_move_snake_flag(t_vars *vars)
{
	t_snake	*init;
	size_t	i;
	size_t	j;

	init = vars->snake;
	while (vars->snake->next != NULL)
	{
		if (vars->snake->prev != NULL)
			ft_swap(&vars->snake->x, &vars->snake->y, &i, &j);
		else
		{
			i = vars->snake->x;
			j = vars->snake->y;
		}
		vars->snake = vars->snake->next;
	}
	vars->snake = init;
	vars->snake->x = vars->x;
	vars->snake->y = vars->y;
}

void	ft_move(int keycode, t_vars *vars)
{
	t_snake	*last;

	ft_checkmove(keycode, vars);
	last = ft_lstlast(vars->snake);
	ft_draw_tile(vars, last->x, last->y, "sprites/floor_tile.xpm");
	vars->map[last->y][last->x] = '0';
	if (vars->flag == 0)
		ft_move_snake(vars);
	else
		ft_move_snake_flag(vars);
	ft_paint_snake(keycode, vars);
}
