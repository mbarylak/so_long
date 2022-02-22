/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:19:03 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/22 21:17:34 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>

# define TILE 32

typedef struct s_snake
{
	size_t			x;
	size_t			y;
	struct s_snake	*next;
	struct s_snake	*prev;
}	t_snake;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	size_t			x;
	size_t			y;
	struct s_snake	*snake;
	size_t			count;
	int				flag;
	size_t			height;
	size_t			width;
	size_t			apple;
}	t_vars;

/* Map Tools */

t_vars	*ft_get_info(char *file, t_vars *vars);
void	ft_make_map(char *file, t_vars *vars);
void	ft_draw_tile(t_vars *vars, size_t x, size_t y, char *imgname);
void	ft_draw_map(char **map, t_vars *vars);

/* Movement Tools */

void	ft_player(int x, int y, t_vars *vars);
void	ft_opendagates(t_vars *vars);
void	ft_checkmove(int keycode, t_vars *vars);
void	ft_checkmove1(t_vars *vars);
void	ft_move(int keycode, t_vars *vars);
int		press_key(int keycode, t_vars *vars);
t_snake	*ft_grow_snake(t_snake *snake);
void	ft_move_snake(t_vars *vars);
void	ft_move_snake_flag(t_vars *vars);
void	ft_paint_head(int keycode, t_vars *vars);
void	ft_paint_snake(int keycode, t_vars *vars);

/* Error Mngt */

void	ft_free(t_vars *vars);
void	ft_freedom(char **map);
int		ft_closed(void);
int		ft_exit(t_vars *vars);
void	ft_error(int n);
void	ft_checkmap1(t_vars *vars);
void	ft_checkmap2(t_vars *vars, int p);
void	ft_checkmap3(t_vars *vars);
void	ft_checkmap4(t_vars *vars);
void	ft_checkmap(t_vars *vars);

/* Lst Utils */

t_snake	*ft_lstlast(t_snake *snake);
void	ft_lstadd_back(t_snake **snake, t_snake *new);
void	ft_swap(size_t	*x, size_t *y, size_t *i, size_t *j);

#endif
