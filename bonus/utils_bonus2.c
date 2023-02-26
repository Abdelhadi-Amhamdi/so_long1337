/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:24:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 12:06:23 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	get_val(int x, int y, t_long *game)
{
	if (x < 0 || y < 0)
		return (0);
	return (game->map[y / game->img->size][x / game->img->size]);
}

void	set_val(t_long *game, int x, int y, char c)
{
	game->map[y / game->img->size][x / game->img->size] = c;
}

t_item	*get_item(int x, int y, t_long *game)
{
	t_item	*tmp;

	tmp = game->coins;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	handle_coins(t_long *g, int x, int y, char c)
{
	t_item	*item;

	if (c == 'C')
	{
		item = get_item(x, y, g);
		item->direction = 'b';
		if (!g->collects_n--)
			mlx_put_image_to_window(g->mlx, g->mlx_w, \
			g->img->oe, g->e_x, g->e_y);
	}
}

void	ft_init_coins_img(t_coin_imgs *img, t_long *game)
{
	int	w;

	w = 64;
	img->c1 = mlx_xpm_file_to_image(game->mlx, "images/css/cs1.xpm", &w, &w);
	img->c1 = mlx_xpm_file_to_image(game->mlx, "images/css/cs1.xpm", &w, &w);
	img->c2 = mlx_xpm_file_to_image(game->mlx, "images/css/cs2.xpm", &w, &w);
	img->c3 = mlx_xpm_file_to_image(game->mlx, "images/css/cs3.xpm", &w, &w);
	img->c4 = mlx_xpm_file_to_image(game->mlx, "images/css/cs4.xpm", &w, &w);
	img->c5 = mlx_xpm_file_to_image(game->mlx, "images/css/cs5.xpm", &w, &w);
	img->c6 = mlx_xpm_file_to_image(game->mlx, "images/css/cs6.xpm", &w, &w);
}
