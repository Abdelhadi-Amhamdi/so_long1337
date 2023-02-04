/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/04 15:09:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
typedef struct so_long
{
    void *mlx;
    void *mlx_win;
    int width;
    int heigth;
    int p_x;
    int p_y;
    int exit_x;
    int exit_y;
    int collects_n;
    char **map;
} to_long;


typedef struct s_images
{
    void *wall_image;
    void *player_right_image;
    void *player_left_image;
    void *player_image;
    void *coins_image;
    void *background_image;
    void *exit_image;
    void *monster_image;
    void *open_exit;
} t_images;

char **read_map(char *map_file);
void ft_draw_map(to_long *game, t_images *images);
int  move_player(int keycode, to_long *game);
void ft_init_images(to_long *game, t_images *images);
char get_val(int x, int y, to_long *game);