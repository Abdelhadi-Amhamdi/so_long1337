/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/04 15:14:52 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

void ft_draw_map(to_long *game, t_images *images)
{
    int x = 0;
    int y = 0;
    char **map;

    map = game->map;
    game->collects_n = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->wall_image, (x * 64), (y * 64));
            else if(map[y][x] == 'C')
            {
                game->collects_n++;
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->coins_image, (x * 64), (y * 64));
            }
            else if(map[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->player_image, (x * 64), (y * 64));
                game->p_x = x * 64;
                game->p_y = y * 64;
            }
            else if(map[y][x] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->exit_image, (x * 64), (y * 64));
                game->exit_x = x * 64;
                game->exit_y = y * 64;
            }
            else if(map[y][x] == 'M')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->monster_image, (x * 64), (y * 64));
            else if(map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->background_image, (x * 64), (y * 64));
            x++;
        }
        y++;
    }
}