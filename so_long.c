/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 16:44:15 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>


void ft_init(to_long *game, t_data *image)
{
    // init game
    game->width = 1920;
    game->heigth = 1080;
    
    // init image
    image->img = "images/wall.xpm";
    image->bits_per_pixel = 50;
    image->line_length = 10;
    image->endian = 0;
}


int main()
{

    struct so_long game;
    struct s_data image;
    
    ft_init(&game, &image);
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.width, game.heigth, "soooo_loooong!");
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);

    mlx_put_image_to_window(game.mlx, game.mlx_win, image.img, 0, 0);
    mlx_loop(game.mlx);

    return (0);
}