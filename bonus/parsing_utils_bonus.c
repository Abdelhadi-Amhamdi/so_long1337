/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:45 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 12:18:36 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*check_all_rows_size(char **map)
{
	int	*sizes;

	sizes = ft_calloc(2, sizeof(int));
	sizes[0] = (int)ft_strlen(*map);
	sizes[1] = 0;
	while (*map)
	{
		if ((int)ft_strlen(*map) != sizes[0])
			return (0);
		map++;
		sizes[1]++;
	}
	return (sizes);
}

int	check_top_and_bottom(char *top, char *bottom)
{
	while (*top)
	{
		if (*top != '1' || *bottom != '1')
			return (0);
		top++;
		bottom++;
	}
	return (1);
}

int	check_sides(char **map, int width)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[index][0] != '1' || map[index][width -1] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	ft_close_window(t_long *g)
{
	handle_enmey_touch_and_exit('e', g);
	return (1);
}

int	check_all_imgs(t_long *game)
{
	t_image		*m;
	t_c_imgs	*c;
	t_m_imgs	*mm;

	m = game->img;
	c = game->c_img;
	mm = game->m_img;
	if (!m->bc || !m->bg || !m->e || !m->oe || \
	!m->pc || !m->pl || !m->pr || !m->wb || !m->wl || !m->wr || !m->wt)
		return (0);
	if (!c->c1 || !c->c2 || !c->c3 || !c->c4 || !c->c5 || !c->c6)
		return (0);
	if (!mm->ml1 || !mm->ml2 || !mm->ml3 || !mm->mr1 || !mm->mr2 || !mm->mr3)
		return (0);
	return (1);
}
