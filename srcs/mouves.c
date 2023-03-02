/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/02 10:19:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_coins(t_long *g, int x, int y, char c)
{
	if (c == 'C' && !g->collects--)
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->eo, g->e_x, g->e_y);
}

int	move_player(int keycode, t_long *g)
{
	static int	mouves;

	g->s = 64;
	if (keycode == 124 || keycode == 2)
		ft_move_right(g, &mouves);
	else if (keycode == 123 || keycode == 0)
		ft_move_left(g, &mouves);
	else if (keycode == 126 || keycode == 13)
		ft_move_top(g, &mouves);
	else if (keycode == 125 || keycode == 1)
		ft_move_buttom(g, &mouves);
	else if (keycode == 53)
		ft_put_end_screen(g);
	if (!g->collects)
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->eo, g->e_x, g->e_y);
	return (1);
}

void	ft_put_end_screen(t_long *g)
{
	free(g->p);
	mlx_destroy_window(g->mlx, g->mlx_w);
	exit(0);
}
