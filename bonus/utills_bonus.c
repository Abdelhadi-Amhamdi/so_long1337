/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:33 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 11:24:58 by aamhamdi         ###   ########.fr       */
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

void	ft_init_images(t_long *game, t_image *img)
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
	img->pc = mlx_xpm_file_to_image(game->mlx, "pc.xpm", &s, &s);
	img->p = mlx_xpm_file_to_image(game->mlx, "images/player/pt.xpm", &s, &s);
	img->bg = mlx_xpm_file_to_image(game->mlx, "images/bg1.xpm", &s, &s);
	img->bc = mlx_xpm_file_to_image(game->mlx, "ledder.xpm", &s, &s);
	img->c = mlx_xpm_file_to_image(game->mlx, "images/css/cs1.xpm", &s, &s);
	img->e = mlx_xpm_file_to_image(game->mlx, "images/ex.xpm", &s, &s);
	img->m = mlx_xpm_file_to_image(game->mlx, "images/ms/mr1.xpm", &s, &s);
	img->oe = mlx_xpm_file_to_image(game->mlx, "images/oe.xpm", &s, &s);
}

void	ft_calc_sizes(int *w, int *h, t_long *game)
{
	if (game->w_w >= 849 && game->w_h >= 512)
	{
		*w = 849;
		*h = 512;
	}
	else if (game->w_w >= 664 && game->w_h >= 320)
	{
		*w = 664;
		*h = 320;
	}
	else
	{
		*w = 375;
		*h = 192;
	}
}

void	ft_put_end_screen(t_long *game, char type)
{
	int		w;
	int		h;
	void	*wm;
	t_item	*monsters;

	monsters = game->monsters;
	ft_calc_sizes(&w, &h, game);
	if (type == 'E')
	{
		wm = mlx_xpm_file_to_image(game->mlx, "images/end/win-lg.xpm", &w, &h);
		printf("you win !!!.\n");
	}
	else
	{
		wm = mlx_xpm_file_to_image(game->mlx, "images/end/over-lg.xpm", &w, &h);
		printf("you die !!!.\n");
	}
	while (monsters)
	{
		monsters->direction = 'a';
		monsters = monsters->next;
	}
	mlx_clear_window(game->mlx, game->mlx_w);
	mlx_put_image_to_window(game->mlx, game->mlx_w, wm, \
	((game->w_w / 2) - w / 2), ((game->w_h / 2) - h / 2));
}
