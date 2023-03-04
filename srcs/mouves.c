/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/04 14:24:37 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_coins(t_long *g, char c)
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

void	ft_destroy_all(t_image *img, t_long *g)
{
	mlx_destroy_image(g->mlx, img->bc);
	mlx_destroy_image(g->mlx, img->bg);
	mlx_destroy_image(g->mlx, img->c);
	mlx_destroy_image(g->mlx, img->e);
	mlx_destroy_image(g->mlx, img->eo);
	mlx_destroy_image(g->mlx, img->pc);
	mlx_destroy_image(g->mlx, img->pl);
	mlx_destroy_image(g->mlx, img->pr);
	mlx_destroy_image(g->mlx, img->pt);
	mlx_destroy_image(g->mlx, img->wb);
	mlx_destroy_image(g->mlx, img->wt);
	mlx_destroy_image(g->mlx, img->wr);
	mlx_destroy_image(g->mlx, img->wl);
}

void	ft_put_end_screen(t_long *g)
{
	free(g->p);
	ft_free(g->map);
	ft_destroy_all(g->img, g);
	mlx_destroy_window(g->mlx, g->mlx_w);
	exit(0);
}
