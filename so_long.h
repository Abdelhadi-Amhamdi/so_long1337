/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/05 15:07:53 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_monster
{
    int monster_x;
    int monster_y;
    char direction;
    struct s_monster *next;
} t_monster;

typedef struct s_player
{
    int player_x;
    int player_y;
    int players_count;
} t_player;

typedef struct so_long
{
    void *mlx;
    void *mlx_win;
    int window_width;
    int window_heigth;
    t_player *player;
    t_monster *monsters;
    t_monster *coins;
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
    int size;
} t_images;

char **read_map(char *map_file);
void ft_draw_map(to_long *game, t_images *images);
int  move_player(int keycode, to_long *game);
void ft_init_images(to_long *game, t_images *images);
char get_val(int x, int y, to_long *game);
void set_val(to_long *game, int x, int y, char c);

#endif