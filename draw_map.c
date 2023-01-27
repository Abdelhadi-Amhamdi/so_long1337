/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/27 16:29:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

void ft_draw_map(to_long *game, t_images *images, t_list *map)
{
    int i = 0;
    int x = 0;
    int y = 0;
    
    while(map)
    {
        i= 0;
        x = 0;
        char *tab = (char *)map->content;
        while(tab[i])
        {
            if(tab[i] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->wall_image, x * 50, y * 50);
            else if(tab[i] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->player_image, x * 50, y * 50);
                game->p_x = x * 50;
                game->p_y = y * 50;
            }
            else if(tab[i] == 'C')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->coins_image, x * 50, y * 50);
            else if(tab[i] == '0')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->background_image, x * 50, y * 50);
            else if(tab[i] == 'E')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->exit_image, x * 50, y * 50);
            else if(tab[i] == 'M')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->monster_image, x * 50, y * 50);
            x++;
            i++;
        }
        map = map->next;
        y++;
    }
}