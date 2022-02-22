/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:41:40 by mbarylak          #+#    #+#             */
/*   Updated: 2022/02/22 21:16:56 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_snake	*ft_lstlast(t_snake *snake)
{
	if (!snake)
		return (NULL);
	while (snake->next != NULL)
		snake = snake->next;
	return (snake);
}

void	ft_lstadd_back(t_snake **snake, t_snake *new)
{
	if (*snake)
		ft_lstlast(*snake)->next = new;
	else
		*snake = new;
}

void	ft_swap(size_t *x, size_t *y, size_t *i, size_t *j)
{
	size_t	aux;

	aux = *x;
	*x = *i;
	*i = aux;
	aux = *y;
	*y = *j;
	*j = aux;
}
