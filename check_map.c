/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:51:55 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/23 19:44:04 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap1(t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < vars->height)
	{
		i = 0;
		while (i < vars->width)
		{
			if (vars->map[j][i] != '1' && vars->map[j][i] != '0' && \
					vars->map[j][i] != 'P' && vars->map[j][i] != 'E' && \
					vars->map[j][i] != 'C')
				ft_error(0, vars);
			i++;
		}
		j++;
	}
}

void	ft_checkmap2(t_vars *vars, int p)
{
	size_t	i;
	size_t	j;
	size_t	e;

	j = -1;
	e = 0;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->map[j][i] == 'P')
			{
				ft_player(i, j, vars);
				p += 1;
			}
			else if (vars->map[j][i] == 'E')
				e += 1;
			else if (vars->map[j][i] == 'C')
				vars->apple += 1;
		}
	}
	if (e <= 0 || vars->apple <= 0 || p != 1)
		ft_error(0, vars);
}

void	ft_checkmap3(t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < vars->height)
	{
		i = -1;
		while (++i < vars->width)
		{
			if (vars->map[0][i] != '1')
				ft_error(0, vars);
		}
		if (vars->map[j][0] != '1' || vars->map[j][vars->width -1] != '1')
			ft_error(0, vars);
	}
	i = -1;
	while (vars->map[vars->height - 1][++i] != '\n')
	{
		if (vars->map[vars->height - 1][i] != '1')
			ft_error(0, vars);
	}
}

void	ft_checkmap4(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = vars->x;
	j = vars->y;
	if (vars->map[j - 1][i - 1] == '1' && vars->map[j - 1][i] == '1' \
			&& vars->map[j][i - 1] == '1' && vars->map[j + 1][i] == '1' \
			&& vars->map[j][i + 1] == '1' && vars->map[j + 1][i + 1] == '1')
		ft_error(0, vars);
}

void	ft_checkmap(t_vars *vars)
{
	if (vars->map)
	{
		ft_checkmap1(vars);
		ft_checkmap2(vars, 0);
		ft_checkmap3(vars);
		ft_checkmap4(vars);
		ft_checkmap5(vars);
	}
}
