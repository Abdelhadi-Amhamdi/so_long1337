/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:33 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 20:58:49 by aamhamdi         ###   ########.fr       */
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
	game->window_width = (ft_strlen(game->map[0]) * 64);
	game->window_heigth = (ft_strtablen(game->map) * 64);
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
