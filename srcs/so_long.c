/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/09 15:22:50 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libc.h"

void	ft_init_images(t_long *game, t_image *img)
{
	int	s;

	s = 64;
	img->wt = mlx_xpm_file_to_image(game->mlx, "images/wall/wall1.xpm", &s, &s);
	img->wb = mlx_xpm_file_to_image(game->mlx, "images/wall/wall3.xpm", &s, &s);
	img->wl = mlx_xpm_file_to_image(game->mlx, "images/wall/wall4.xpm", &s, &s);
	img->wr = mlx_xpm_file_to_image(game->mlx, "images/wall/wall2.xpm", &s, &s);
	img->pr = mlx_xpm_file_to_image(game->mlx, "images/player/pr.xpm", &s, &s);
	img->pl = mlx_xpm_file_to_image(game->mlx, "images/player/pl.xpm", &s, &s);
	img->pt = mlx_xpm_file_to_image(game->mlx, "images/player/pt.xpm", &s, &s);
	img->c = mlx_xpm_file_to_image(game->mlx, "images/cs/cs1.xpm", &s, &s);
	img->pc = mlx_xpm_file_to_image(game->mlx, "images/pc.xpm", &s, &s);
	img->bg = mlx_xpm_file_to_image(game->mlx, "images/bg1.xpm", &s, &s);
	img->bc = mlx_xpm_file_to_image(game->mlx, "images/ledder.xpm", &s, &s);
	img->e = mlx_xpm_file_to_image(game->mlx, "images/ex.xpm", &s, &s);
	img->eo = mlx_xpm_file_to_image(game->mlx, "images/oe.xpm", &s, &s);
}

int	close_window(t_long *g)
{
	ft_close_window(g, 'e');
	return (1);
}

int	main(int ac, char **av)
{
	struct so_long	game;
	struct s_images	images;

	game.map = parsing(ac, av[1]);
	if (!game.map)
		return (0);
	game.p = malloc(sizeof(t_player));
	if (!game.p)
		return (0);
	get_player_position(&game);
	if (!check_valid_path(&game))
		return (ft_putendl_fd("invalid map!!", 2), 0);
	calc_window_size(&game);
	game.mlx = mlx_init();
	game.mlx_w = mlx_new_window(game.mlx, game.win_w, game.win_h, "GAME");
	ft_init_images(&game, &images);
	game.img = &images;
	ft_draw_map(&game);
	mlx_hook(game.mlx_w, 2, 0, move_player, &game);
	mlx_hook(game.mlx_w, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
