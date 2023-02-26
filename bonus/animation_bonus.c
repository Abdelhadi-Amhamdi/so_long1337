/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:47:49 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 11:40:23 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	monster_animation_x(t_item *ms, t_long *g, t_monster_imgs *m)
{
	if (ms->direction == 'r')
	{
		if (get_val(ms->x + 64, ms->y, g) == 'P')
			ft_put_end_screen(g, 'l');
		set_val(g, (ms->x), (ms->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, ms->x, ms->y);
		ms->x += 64;
		set_val(g, (ms->x), (ms->y), 'M');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->mr2, ms->x, ms->y);
		if (get_val(ms->x + 64, ms->y, g) == '1')
			ms->direction = 'l';
	}
	else if (ms->direction == 'l')
	{
		if (get_val(ms->x - 64, ms->y, g) == 'P')
			ft_put_end_screen(g, 'l');
		set_val(g, (ms->x), (ms->y), '0');
		mlx_put_image_to_window(g->mlx, g->mlx_w, g->img->bg, (ms->x), (ms->y));
		ms->x -= 64;
		set_val(g, (ms->x), (ms->y), 'M');
		mlx_put_image_to_window(g->mlx, g->mlx_w, m->ml1, ms->x, ms->y);
		if (get_val(ms->x - 64, ms->y, g) == '1')
			ms->direction = 'r';
	}
}
