/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/21 19:06:17 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_images(t_long *game, t_image *img)
{
	int	size;

	size = 64;
	img->bg = mlx_xpm_file_to_image(game->mlx, "images/bg.xpm", &size, &size);
	img->w = mlx_xpm_file_to_image(game->mlx, "images/w.xpm", &size, &size);
	img->pr = mlx_xpm_file_to_image(game->mlx, "images/pr.xpm", &size, &size);
	img->pl = mlx_xpm_file_to_image(game->mlx, "images/pl.xpm", &size, &size);
	img->p = mlx_xpm_file_to_image(game->mlx, "images/p.xpm", &size, &size);
	img->c = mlx_xpm_file_to_image(game->mlx, "images/cs/c1.xpm", &size, &size);
	img->ex = mlx_xpm_file_to_image(game->mlx, "images/ex.xpm", &size, &size);
	img->eo = mlx_xpm_file_to_image(game->mlx, "images/oe.xpm", &size, &size);
}

int	ft_close(int keycode, t_long *game, t_image *images)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	return (0);
}

int	main(int ac, char **av)
{
	struct so_long	game;
	struct s_images	images;

	game.player = malloc(sizeof(t_player));
	game.map = read_map(av[1]);
	if (!game.map)
		return (0);
	calc_window_size(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.win_w, game.win_h, "GAME");
	ft_init_images(&game, &images);
	game.images = &images;
	ft_draw_map(&game);
	if (!check_valid_path(&game))
		return (ft_putendl_fd("invalid map!!", 2), 0);
	mlx_hook(game.mlx_win, 2, (1L << 0), move_player, &game);
	mlx_loop(game.mlx);
	return (0);
}
