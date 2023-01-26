/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 22:52:49 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void ft_init(to_long *game, t_data *image)
{
    // init game
    game->width = 1920;
    game->heigth = 1080;
}


int main()
{

    struct so_long game;
    struct s_data image;
    int width = 50;
    int heigth = 50;

    ft_init(&game, &image);
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.width, game.heigth, "soooo_loooong!");
    image.img = mlx_xpm_file_to_image(game.mlx, "images/wall.xpm", &width, &heigth);
    mlx_put_image_to_window(game.mlx, game.mlx_win, image.img, 0, 0);
    mlx_loop(game.mlx);

    return (0);
}