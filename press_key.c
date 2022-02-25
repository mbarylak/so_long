/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:22 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/25 17:23:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		printf("Closed\n");
		ft_free(vars);
		exit(1);
	}
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		vars->count += 1;
		printf("movements: %d\n", (int) vars->count);
		ft_move(keycode, vars);
	}
	return (0);
}

int	ft_closed(t_vars *vars)
{
	printf("Closed\n");
	ft_free(vars);
	exit(1);
	return (0);
}

int	ft_exit(t_vars *vars)
{
	if (vars->apple == 0)
	{
		if (vars->map[vars->y][vars->x] == 'E')
		{
			printf("Congratulations!\n");
			ft_free(vars);
			exit(1);
		}
		return (1);
	}
	return (0);
}

void	ft_free(t_vars *vars)
{
	size_t	i;

	if (vars->map)
	{
		i = -1;
		while (++i < vars->height)
			free(vars->map[i]);
		free(vars->map);
	}
	if (vars->snake)
	{
		while (vars->snake->next != NULL)
		{
			free(vars->snake);
			vars->snake = vars->snake->next;
		}
		free(vars->snake);
	}
	if (vars->mlx && vars->win)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
	}
}
