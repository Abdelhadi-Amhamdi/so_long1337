/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 12:06:18 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_monster_images(t_monster_imgs *img, t_long *game)
{
	int	w;

	w = 64;
	img->mr1 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr1.xpm", &w, &w);
	img->mr2 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr2.xpm", &w, &w);
	img->mr3 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr3.xpm", &w, &w);
	img->ml1 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml1.xpm", &w, &w);
	img->ml2 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml2.xpm", &w, &w);
	img->ml3 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml3.xpm", &w, &w);
}

void	ft_coins_animation(t_long *game, t_coin_imgs *m)
{
	t_item		*c;
	static int	i;
	static int	j;

	c = game->coins;
	while (c && (i % 150 == 0) && c->direction == 'r')
	{
		if (j == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c1, c->x, c->y);
		else if (j == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c2, c->x, c->y);
		else if (j == 2)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c3, c->x, c->y);
		else if (j == 3)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c4, c->x, c->y);
		else if (j == 4)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c5, c->x, c->y);
		else if (j == 5)
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c6, c->x, c->y);
		if (j == 6)
			j = 0;
		j++;
		c = c->next;
	}
	i++;
}

void	ft_monsters_animation(t_long *g, t_monster_imgs *m)
{
	static int	i;
	t_item		*e;

	e = g->monsters;
	while (e && (i % 500 == 0))
	{
		if (e->direction == 'r')
		{
			if (e->j % 2 == 0)
				mlx_put_image_to_window(g->mlx, g->mlx_w, m->mr2, e->x, e->y);
			else if (e->j % 2 == 1)
				mlx_put_image_to_window(g->mlx, g->mlx_w, m->mr3, e->x, e->y);
		}
		else if (e->direction == 'l')
		{
			if (e->j % 2 == 0)
				mlx_put_image_to_window(g->mlx, g->mlx_w, m->ml2, e->x, e->y);
			else if (e->j % 2 == 1)
				mlx_put_image_to_window(g->mlx, g->mlx_w, m->ml1, e->x, e->y);
		}
		e->j++;
		monster_animation_x(e, g, m);
		e = e->next;
	}
	i++;
}

int	ft_animation(t_long *game)
{
	t_monster_imgs	m_img;
	t_coin_imgs		c_img;

	ft_init_monster_images(&m_img, game);
	ft_init_coins_img(&c_img, game);
	ft_coins_animation(game, &c_img);
	ft_monsters_animation(game, &m_img);
	return (0);
}

int	main(int ac, char **av)
{
	t_long		game;
	t_image		images;

	game.p = malloc(sizeof(t_player));
	if (!game.p)
		return (0);
	game.p->x = 0;
	game.p->y = 0;
	game.monsters = NULL;
	game.coins = NULL;
	game.map = read_map(av[1]);
	if (!game.map)
		return (0);
	calc_size(&game);
	game.mlx = mlx_init();
	game.mlx_w = mlx_new_window(game.mlx, game.w_w, game.w_h, "so_long!");
	ft_init_images(&game, &images);
	game.img = &images;
	ft_draw_map(&game);
	mlx_hook(game.mlx_w, 2, (1L << 0), move_player, &game);
	mlx_loop_hook(game.mlx, ft_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
