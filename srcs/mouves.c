/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 16:40:08 by aamhamdi         ###   ########.fr       */
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
	g->s = 64;
	if (keycode == 124)
		ft_move_right(g);
	else if (keycode == 123)
		ft_move_left(g);
	else if (keycode == 126)
		ft_move_buttom(g);
	else if (keycode == 125)
		ft_move_top(g);
	if (!g->collects)
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->eo, g->e_x, g->e_y);
	return (1);
}

void	ft_calc_sizes(int *w, int *h, t_long *g)
{
	if (g->win_w >= 849 && g->win_h >= 512)
	{
		*w = 849;
		*h = 512;
	}
	else if (g->win_w >= 664 && g->win_h >= 320)
	{
		*w = 664;
		*h = 320;
	}
	else
	{
		*w = 375;
		*h = 192;
	}
}

void	ft_put_end_screen(t_long *g, char type)
{
	int		w ;
	int		h ;
	void	*img;

	ft_calc_sizes(&w, &h, g);
	if (type == 'w')
	{
		printf("you win !!!. %d %d\n", g->win_h, g->win_w);
	}
	img = mlx_xpm_file_to_image(g->mlx, "images/end/win-lg.xpm", &w, &h);
	mlx_put_image_to_window(g->mlx, g->mlx_w, img, \
	((g->win_w / 2) - w / 2), ((g->win_h / 2) - h / 2));
}
