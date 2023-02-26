/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 11:19:17 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mouve_left(t_long *g, t_image *m)
{
	char	item;

	item = get_val((g->p->x - 64), g->p->y, g);
	if (item == '0' || item == 'C')
	{
		handle_coins(g, g->p->x - 64, g->p->y, item);
		set_val(g, (g->p->x), (g->p->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x -= 64), (g->p->y), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->pl, g->p->x, g->p->y);
	}
}

void	ft_mouve_right(t_long *g, t_image *m)
{
	char	item;

	item = get_val((g->p->x + 64), g->p->y, g);
	if (item == '0' || item == 'C')
	{
		handle_coins(g, g->p->x + 64, g->p->y, item);
		set_val(g, (g->p->x), (g->p->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, g->p->x, g->p->y);
		set_val(g, (g->p->x += 64), (g->p->y), 'P');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->pr, g->p->x, g->p->y);
	}
}

void	ft_mouve_top(t_long *g, t_image *m)
{
	char	item;

	item = get_val(g->p->x, g->p->y - 64, g);
	if (item == '0' || item == 'C')
	{
		handle_coins(g, g->p->x, g->p->y - 64, item);
		set_val(g, (g->p->x), (g->p->y), '0');
		set_val(g, (g->p->x), (g->p->y -= 64), 'P');
		if (get_val(g->p->x + 64, g->p->y - 64, g) == '1' && \
		get_val(g->p->x - 64, g->p->y - 64, g) == '1')
		{
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bc, \
			g->p->x, g->p->y + 64);
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->pc, g->p->x, g->p->y);
		}
		else
		{
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, \
			g->p->x, g->p->y + 64);
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->p, g->p->x, g->p->y);
		}
	}
}

void	ft_mouve_buttom(t_long *g, t_image *m)
{
	char	item;

	item = get_val(g->p->x, g->p->y + 64, g);
	if (item == '0' || item == 'C')
	{
		handle_coins(g, g->p->x, g->p->y + 64, item);
		set_val(g, (g->p->x), (g->p->y), '0');
		set_val(g, (g->p->x), (g->p->y += 64), 'P');
		if (get_val(g->p->x + 64, g->p->y - 64, g) == '1' && \
		get_val(g->p->x + 64, g->p->y - 64, g) == '1')
		{
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bc, g->p->x, \
			g->p->y - 64);
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->pc, g->p->x, g->p->y);
		}
		else
		{
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->bg, \
			g->p->x, g->p->y - 64);
			mlx_put_image_to_window(g->mlx, g->mlx_w, m->p, g->p->x, g->p->y);
		}
	}
	else
		ft_put_end_screen(g, item);
}

int	move_player(int keycode, t_long *game)
{
	if (keycode == 123)
		ft_mouve_left(game, game->img);
	else if (keycode == 124)
		ft_mouve_right(game, game->img);
	else if (keycode == 126)
		ft_mouve_top(game, game->img);
	else if (keycode == 125)
		ft_mouve_buttom(game, game->img);
	return (1);
}
