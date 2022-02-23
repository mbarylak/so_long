/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:44:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/23 20:20:04 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkinput(const char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e' \
				&& argv[i + 3] == 'r')
			return (1);
		i++;
	}
	return (0);
}
