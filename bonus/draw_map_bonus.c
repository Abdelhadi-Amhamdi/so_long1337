/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 20:06:55 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_item	*ft_lst_creat(int mx, int my)
{
	t_item	*m;

	m = malloc(sizeof(t_item));
	if (!m)
		return (NULL);
	m->item_x = mx;
	m->item_y = my;
	m->direction = 'r';
	m->next = NULL;
	return (m);
}

t_item	*last_lst(t_item *items)
{
	t_item	*tmp;

	tmp = items;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lst_add_back(t_item **items, t_item *new_item)
{
	t_item	*l;

	if (*items)
	{
		l = last_lst(*items);
		l->next = new_item;
	}
	else
		*items = new_item;
}

void	create_item(int mx, int my, t_item **items)
{
	t_item	*item;

	item = ft_lst_creat(mx, my);
	ft_lst_add_back(items, item);
}

void	ft_draw_map(t_long *game, t_image *images)
{
	int		x;
	int		y;

	y = 0;
	game->collects_n = 0;
	while (game->map[y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				ft_draw_walls(game, images, x, y);
			else if (game->map[y][x] == '0')
				ft_draw_background(game, images, x, y);
			else if (game->map[y][x] == 'C')
				ft_draw_coins(game, images, x, y);
			else if (game->map[y][x] == 'P')
				ft_draw_player(game, images, x, y);
			else if (game->map[y][x] == 'E')
				ft_draw_exit(game, images, x, y);
			else if (game->map[y][x] == 'M')
				ft_draw_monster(game, images, x, y);
		}
		y++;
	}
}
