/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_snake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:50:11 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/23 19:53:44 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmove(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->y -= 1;
	else if (keycode == 1)
		vars->y += 1;
	else if (keycode == 0)
		vars->x -= 1;
	else if (keycode == 2)
		vars->x += 1;
	ft_checkmove1(vars);
}

void	ft_checkmove1( t_vars *vars)
{
	if (vars->map[vars->y][vars->x] == '1' || (vars->map[vars->y][vars->x] == \
				'E' && ft_exit(vars) == 0))
		ft_error(1, vars);
	else if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->snake = ft_grow_snake(vars->snake);
		vars->map[vars->y][vars->x] = '0';
		vars->apple -= 1;
		vars->flag = 1;
		vars->s_count += 1;
		if (vars->apple == 0)
			ft_opendagates(vars);
	}
	else if (vars->map[vars->y][vars->x] == 'B')
		ft_error(1, vars);
	else
		vars->flag = 0;
}

t_snake	*ft_grow_snake(t_snake *snake)
{
	t_snake	*last;
	t_snake	*init;
	t_snake	*new;

	init = snake;
	last = ft_lstlast(snake);
	new = (t_snake *)malloc(sizeof(t_snake));
	if (!new)
		return (NULL);
	new->x = last->x;
	new->y = last->y;
	ft_lstlast(snake)->next = new;
	new->prev = snake;
	new->next = NULL;
	snake = init;
	return (snake);
}

void	ft_paint_head(int keycode, t_vars *vars)
{
	if (keycode == 0)
		ft_draw_tile(vars, vars->snake->x, vars->snake->y, \
				"sprites/snekLeft.xpm");
	else if (keycode == 2)
		ft_draw_tile(vars, vars->snake->x, vars->snake->y, \
				"sprites/snekRight.xpm");
	else if (keycode == 13)
		ft_draw_tile(vars, vars->snake->x, vars->snake->y, \
				"sprites/snekUp.xpm");
	else if (keycode == 1)
		ft_draw_tile(vars, vars->snake->x, vars->snake->y, \
				"sprites/snekDown.xpm");
}

void	ft_paint_snake(int keycode, t_vars *vars)
{
	t_snake	*init;

	init = vars->snake;
	ft_paint_head(keycode, vars);
	while (vars->snake != NULL)
	{
		if (vars->snake->prev != NULL)
		{
			ft_draw_tile(vars, vars->snake->x, vars->snake->y, \
					"sprites/body_tile.xpm");
			vars->map[vars->snake->y][vars->snake->x] = 'B';
		}
		vars->snake = vars->snake->next;
	}
	vars->snake = init;
}
