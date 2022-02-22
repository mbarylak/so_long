/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:22 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/22 19:33:13 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		printf("Closed\n");
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

int	ft_closed(void)
{
	printf("Closed\n");
	exit(1);
	return (0);
}

int	ft_exit(t_vars *vars)
{
	if (vars->apple == 0)
	{
		if (vars->map[vars->y][vars->x] == 'E')
		{
			printf("Game Finished!\n");
			exit(1);
		}
		return (1);
	}
	return (0);
}
