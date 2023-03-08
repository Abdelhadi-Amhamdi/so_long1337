/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:39:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/07 12:08:35 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_long *g, int *mouves)
{
	char	c;

	c = get_val((g->p->x + g->s), g->p->y, g);
	if (c != '1' && c != 'E')
	{
		handle_coins(g, c);
		set_val(g, (g->p->x), (g->p->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x += g->s), (g->p->y), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->pr, g->p->x, g->p->y);
		(*mouves)++;
		ft_putnbr_fd(*mouves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (c == 'E' && !g->collects)
		ft_close_window(g, c);
}

void	ft_move_left(t_long *g, int *mouves)
{
	char	c;

	c = get_val((g->p->x - g->s), g->p->y, g);
	if (c != '1' && c != 'E')
	{
		handle_coins(g, c);
		set_val(g, (g->p->x), (g->p->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x -= g->s), (g->p->y), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->pl, g->p->x, g->p->y);
		(*mouves)++;
		ft_putnbr_fd(*mouves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (c == 'E' && !g->collects)
		ft_close_window(g, c);
}

void	ft_move_buttom(t_long *g, int *mouves)
{
	char	c;
	t_image	*m;

	m = g->img;
	c = get_val(g->p->x, (g->p->y + g->s), g);
	if (c != '1' && c != 'E')
	{
		handle_coins(g, c);
		set_val(g, (g->p->x), (g->p->y), '0');
		if (get_val(g->p->x + 64, g->p->y, g) == '1' && \
		get_val(g->p->x - 64, g->p->y, g) == '1' && ((g->p->y / 64) - 1 != 0))
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bc, g->p->x, g->p->y);
		else
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x), (g->p->y += g->s), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->pc, g->p->x, g->p->y);
		(*mouves)++;
		ft_putnbr_fd(*mouves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (c == 'E' && !g->collects)
		ft_close_window(g, c);
}

void	ft_move_top(t_long *g, int *mouves)
{
	char	c;
	t_image	*m;

	m = g->img;
	c = get_val((g->p->x), (g->p->y - g->s), g);
	if (c != '1' && c != 'E')
	{
		handle_coins(g, c);
		set_val(g, (g->p->x), (g->p->y), '0');
		if ((get_val(g->p->x + 64, g->p->y, g) == '1' && get_val(g->p->x - 64, \
		g->p->y, g) == '1') && ((g->p->y / 64) + 2 != g->win_h / 64))
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bc, g->p->x, g->p->y);
		else
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x), (g->p->y -= g->s), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->pc, g->p->x, g->p->y);
		(*mouves)++;
		ft_putnbr_fd(*mouves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (c == 'E' && !g->collects)
		ft_close_window(g, c);
}
