/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:47:49 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/03 21:27:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_monster_to_left(t_item *ms, t_long *g, t_monster_imgs *m)
{
	if (get_val(ms->x - 64, ms->y, g) == 'P')
		ft_put_end_screen(g, 'l');
	set_val(g, (ms->x), (ms->y), '0');
	mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, (ms->x), (ms->y));
	ms->x -= 64;
	set_val(g, (ms->x), (ms->y), 'M');
	mlx_put_image_to_window(g->mlx, g->mlx_w, m->ml1, ms->x, ms->y);
}

void	ft_monster_to_right(t_item *ms, t_long *g, t_monster_imgs *m)
{
	if (get_val(ms->x + 64, ms->y, g) == 'P')
		ft_put_end_screen(g, 'l');
	set_val(g, (ms->x), (ms->y), '0');
	mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, ms->x, ms->y);
	ms->x += 64;
	set_val(g, (ms->x), (ms->y), 'M');
	mlx_put_image_to_window(g->mlx, g->mlx_w, m->mr2, ms->x, ms->y);
}

void	monster_animation_x(t_item *ms, t_long *g, t_monster_imgs *m)
{
	if (ms->direction == 'r')
	{
		if (get_val(ms->x + 64, ms->y, g) == '1')
		{
			ms->direction = 'l';
			return ;
		}
		ft_monster_to_right(ms, g, m);
	}
	else if (ms->direction == 'l')
	{
		if (get_val(ms->x - 64, ms->y, g) == '1')
		{
			ms->direction = 'r';
			return ;
		}
		ft_monster_to_left(ms, g, m);
	}
}

void	ft_init(t_long *game)
{
	game->coins = NULL;
	game->monsters = NULL;
	game->moves = 0;
	game->collects_n = 0;
	game->p = NULL;
}
