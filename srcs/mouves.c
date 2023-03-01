/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/01 11:53:30 by aamhamdi         ###   ########.fr       */
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
	if (!g->collects)
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->eo, g->e_x, g->e_y);
	return (1);
}

int	ft_calc_sizes(int *w, int *h, t_long *g)
{
	int	ret;

	ret = 0;
	if (g->win_w >= 849 && g->win_h >= 512)
	{
		*w = 849;
		*h = 512;
		ret = 1;
	}
	else if (g->win_w >= 664 && g->win_h >= 320)
	{
		*w = 664;
		*h = 320;
		ret = 2;
	}
	else
	{
		*w = 375;
		*h = 192;
		ret = 3;
	}
	return (ret);
}

void	ft_put_end_screen(t_long *g)
{
	int		w;
	int		h;
	int		s;
	void	*img;

	s = ft_calc_sizes(&w, &h, g);
	if (s == 1)
		img = mlx_xpm_file_to_image(g->mlx, "images/end/win-lg.xpm", &w, &h);
	else if (s == 2)
		img = mlx_xpm_file_to_image(g->mlx, "images/end/win-md.xpm", &w, &h);
	else
		img = mlx_xpm_file_to_image(g->mlx, "images/end/win-sm.xpm", &w, &h);
	mlx_put_image_to_window(g->mlx, g->mlx_w, img, \
	((g->win_w / 2) - w / 2), ((g->win_h / 2) - h / 2));
	free(g->p);
}
