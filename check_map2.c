/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:36:15 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/23 19:43:02 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkmap5(t_vars *vars)
{
	size_t	j;
	size_t	i;

	j = -1;
	while (++j < vars->height)
	{
		i = 0;
		while (vars->map[j][i] != '\n')
			i++;
		if (i != vars->width)
			ft_error(0, vars);
	}
}
