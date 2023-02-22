/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 21:37:19 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

typedef struct s_items
{
	int				item_x;
	int				item_y;
	char			direction;
	struct s_items	*next;
}	t_item;

typedef struct s_players
{
	int	player_x;
	int	player_y;
}	t_player;

typedef struct so_long
{
	void		*mlx;
	void		*mlx_w;
	int			window_width;
	int			window_heigth;
	t_player	*player;
	t_item		*monsters;
	t_item		*coins;
	int			exit_x;
	int			exit_y;
	int			collects_n;
	char		**map;
}	t_long;

typedef struct s_coin_imgs
{
	void *c1;
	void *c2;
	void *c3;
	void *c4;
	void *c5;
	void *c6;
} t_coin_imgs;

typedef struct s_monster_imgs
{
	void *mr1;
	void *mr2;
	void *mr3;
	void *ml4;
	void *ml5;
	void *ml6;
} t_monster_imgs;

typedef struct s_images
{
	void	*wt;
	void	*wb;
	void	*wl;
	void	*wr;
	void	*pr;
	void	*pl;
	void	*pc;
	void	*p;
	void	*c;
	void	*bg;
	void	*bc;
	void	*e;
	void	*m;
	void	*oe;
	int		size;
}	t_image;

char	**read_map(char *map_file);
void	ft_draw_map(t_long *game, t_image *images);
int		move_player(int keycode, t_long *game);
void	ft_init_images(t_long *game, t_image *images);
char	get_val(int x, int y, t_long *game);
void	set_val(t_long *game, int x, int y, char c);

void	ft_put_end_screen(t_long *game, char type);
void	calc_size(t_long *game);
t_item	*ft_lst_creat(int mx, int my);
t_item	*last_lst(t_item *items);
void	ft_lst_add_back(t_item **items, t_item *new_item);
void	create_item(int mx, int my, t_item **items);

void	ft_draw_background(t_long *game, t_image *img, int x, int y);
void	ft_draw_player(t_long *game, t_image *img, int x, int y);
void	ft_draw_coins(t_long *game, t_image *img, int x, int y);
void	ft_draw_monster(t_long *game, t_image *img, int x, int y);
void	ft_draw_walls(t_long *game, t_image *img, int x, int y);
void	ft_draw_exit(t_long *game, t_image *img, int x, int y);

#endif