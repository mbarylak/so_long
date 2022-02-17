/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:50:17 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/17 21:26:10 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		printf("Invalid map input\n");
		exit(1);
	}
}

t_vars	*ft_init(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->x = 0;
	vars->y = 0;
	vars->count = 0;
	vars->height = 0;
	vars->width = 0;
	vars->apple = 0;
	return (vars);
}

void	leak(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		w;
	int		h;

	atexit(leak);
	vars = ft_init();
	vars->mlx = mlx_init();
	if (argc != 2)
		return (0);
	vars = ft_get_info(argv[1], vars);
	ft_make_map(argv[1], vars);
	ft_checkmap(vars);
	w = vars->width * TILE;
	h = vars->height * TILE;
	vars->win = mlx_new_window(vars->mlx, w, h, "so_long");
	if (!vars->win)
		ft_error(0);
	ft_draw_map(vars->map, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_closed, vars);
	mlx_key_hook(vars->win, press_key, vars);
	mlx_loop(vars->mlx);
	return (0);
}