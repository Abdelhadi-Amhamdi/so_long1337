/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 12:54:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_monster_images(t_m_imgs *img, t_long *game)
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

void	ft_coins_animation(t_long *game, t_c_imgs *m)
{
	t_item		*c;
	static int	i;
	static int	j;

	c = game->coins;
	while (c && (i % 1500 == 0))
	{
		if (j == 0 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c1, c->x, c->y);
		else if (j == 1 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c2, c->x, c->y);
		else if (j == 2 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c3, c->x, c->y);
		else if (j == 3 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c4, c->x, c->y);
		else if (j == 4 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c5, c->x, c->y);
		else if (j == 5 && c->direction == 'r')
			mlx_put_image_to_window(game->mlx, game->mlx_w, m->c6, c->x, c->y);
		if (j == 6)
			j = 0;
		j++;
		c = c->next;
	}
	i++;
}

void	ft_monsters_animation(t_long *g, t_m_imgs *m)
{
	static int	i;
	t_item		*e;

	e = g->monsters;
	while (e && (i % 3000 == 0))
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
	ft_coins_animation(game, game->c_img);
	ft_monsters_animation(game, game->m_img);
	return (0);
}

int	main(int ac, char **av)
{
	t_long		game;
	t_image		images;
	t_m_imgs	m_img;
	t_c_imgs	c_img;

	game.map = parsing(ac, av[1]);
	if (!game.map)
		return (0);
	ft_init(&game);
	if (!game.p)
		return (ft_free(game.map), 0);
	if (!check_for_valid_path(&game))
		return (ft_putendl_fd("Error\ninvalid map", 1), 0);
	calc_size(&game);
	game.mlx = mlx_init();
	game.mlx_w = mlx_new_window(game.mlx, game.w_w, game.w_h, "so_long!");
	if (!ft_init_images(&game, &images, &c_img, &m_img))
		return (ft_free(game.map), 0);
	ft_draw_map(&game);
	mlx_hook(game.mlx_w, 2, 0, move_player, &game);
	mlx_hook(game.mlx_w, 17, 0, ft_close_window, &game);
	mlx_loop_hook(game.mlx, ft_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}
