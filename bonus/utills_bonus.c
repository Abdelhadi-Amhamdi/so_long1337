/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:33 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 12:52:05 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strtablen(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
		i++;
	return (i);
}

void	calc_size(t_long *game)
{
	game->w_w = (ft_strlen(game->map[0]) * 64);
	game->w_h = (ft_strtablen(game->map) * 64);
}

int	ft_init_images(t_long *game, t_image *img, \
t_c_imgs *c_img, t_m_imgs *m_img)
{
	int	s;

	img->size = 64;
	s = img->size;
	img->wt = mlx_xpm_file_to_image(game->mlx, "images/wall/wall1.xpm", &s, &s);
	img->wb = mlx_xpm_file_to_image(game->mlx, "images/wall/wall3.xpm", &s, &s);
	img->wl = mlx_xpm_file_to_image(game->mlx, "images/wall/wall4.xpm", &s, &s);
	img->wr = mlx_xpm_file_to_image(game->mlx, "images/wall/wall2.xpm", &s, &s);
	img->pr = mlx_xpm_file_to_image(game->mlx, "images/player/pr.xpm", &s, &s);
	img->pl = mlx_xpm_file_to_image(game->mlx, "images/player/pl.xpm", &s, &s);
	img->pc = mlx_xpm_file_to_image(game->mlx, "images/pc.xpm", &s, &s);
	img->bg = mlx_xpm_file_to_image(game->mlx, "images/bg1.xpm", &s, &s);
	img->bc = mlx_xpm_file_to_image(game->mlx, "images/ledder.xpm", &s, &s);
	img->e = mlx_xpm_file_to_image(game->mlx, "images/ex.xpm", &s, &s);
	img->oe = mlx_xpm_file_to_image(game->mlx, "images/oe.xpm", &s, &s);
	ft_init_monster_images(m_img, game);
	ft_init_coins_img(c_img, game);
	game->c_img = c_img;
	game->m_img = m_img;
	game->img = img;
	if (!check_all_imgs(game))
		return (free(game->p), 0);
	return (1);
}

void	ft_free_list(t_item *item)
{
	t_item	*tmp;
	t_item	*next;

	tmp = item;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

void	ft_destroy_all(t_image *img, t_long *g)
{
	mlx_destroy_image(g->mlx, img->bc);
	mlx_destroy_image(g->mlx, img->bg);
	mlx_destroy_image(g->mlx, img->e);
	mlx_destroy_image(g->mlx, img->oe);
	mlx_destroy_image(g->mlx, img->pc);
	mlx_destroy_image(g->mlx, img->pl);
	mlx_destroy_image(g->mlx, img->pr);
	mlx_destroy_image(g->mlx, img->wb);
	mlx_destroy_image(g->mlx, img->wt);
	mlx_destroy_image(g->mlx, img->wr);
	mlx_destroy_image(g->mlx, img->wl);
	mlx_destroy_image(g->mlx, g->c_img->c1);
	mlx_destroy_image(g->mlx, g->c_img->c2);
	mlx_destroy_image(g->mlx, g->c_img->c3);
	mlx_destroy_image(g->mlx, g->c_img->c4);
	mlx_destroy_image(g->mlx, g->c_img->c5);
	mlx_destroy_image(g->mlx, g->c_img->c6);
	mlx_destroy_image(g->mlx, g->m_img->ml1);
	mlx_destroy_image(g->mlx, g->m_img->ml2);
	mlx_destroy_image(g->mlx, g->m_img->ml3);
	mlx_destroy_image(g->mlx, g->m_img->mr1);
	mlx_destroy_image(g->mlx, g->m_img->mr2);
	mlx_destroy_image(g->mlx, g->m_img->mr3);
}
