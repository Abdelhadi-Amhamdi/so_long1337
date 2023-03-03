/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/03 22:21:51 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

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

typedef struct s_parsing_items
{
	int	p;
	int	e;
	int	c;
	int	rows;
	int	index;
}	t_parsing_items;

typedef struct s_items
{
	int				x;
	int				y;
	char			direction;
	int				j;
	struct s_items	*next;
}	t_item;

typedef struct s_players
{
	int	x;
	int	y;
}	t_player;

typedef struct so_long
{
	void		*mlx;
	void		*mlx_w;
	int			w_w;
	int			w_h;
	t_player	*p;
	t_item		*monsters;
	t_item		*coins;
	t_image		*img;
	int			e_x;
	int			e_y;
	int			collects_n;
	char		**map;
	int			moves;
}	t_long;

typedef struct s_coin_imgs
{
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
	void	*c5;
	void	*c6;
}	t_coin_imgs;

typedef struct s_monster_imgs
{
	void	*mr1;
	void	*mr2;
	void	*mr3;
	void	*ml1;
	void	*ml2;
	void	*ml3;
}	t_monster_imgs;

//read map
char	**read_map(char *map_file);

//draw map
void	ft_draw_map(t_long *game);
void	ft_draw_background(t_long *game, t_image *img, int x, int y);
void	ft_draw_player(t_long *game, t_image *img, int x, int y);
void	ft_draw_coins(t_long *game, t_image *img, int x, int y);
void	ft_draw_monster(t_long *game, t_image *img, int x, int y);
void	ft_draw_walls(t_long *game, t_image *img, int x, int y);
void	ft_draw_exit(t_long *game, t_image *img, int x, int y);
void	ft_put_end_screen(t_long *game, char type);
void	handle_coins(t_long *g, int x, int y, char c);

//mouves
int		move_player(int keycode, t_long *game);
void	ft_mouve_buttom(t_long *g, t_image *m);
void	ft_mouve_top(t_long *g, t_image *m);
void	ft_mouve_right(t_long *g, t_image *m);
void	ft_mouve_left(t_long *g, t_image *m);
void	handle_enmey_touch_and_exit(char item, t_long *g);

//imgs initialization
void	ft_init_images(t_long *game, t_image *images);
void	ft_init_coins_img(t_coin_imgs *img, t_long *game);
void	ft_init_monster_images(t_monster_imgs *img, t_long *game);

//utils
int		ft_strtablen(char **tabs);
char	get_val(int x, int y, t_long *game);
void	set_val(t_long *game, int x, int y, char c);
void	calc_size(t_long *game);
void	ft_calc_sizes(int *w, int *h, t_long *game);
t_item	*get_item(int x, int y, t_long *game);
void	get_player_position(t_long *game);
void	ft_init(t_long *game);

//animation
int		ft_animation(t_long *game);
void	ft_monsters_animation(t_long *g, t_monster_imgs *m);
void	ft_coins_animation(t_long *game, t_coin_imgs *m);
void	monster_animation_x(t_item *monster, t_long *game, t_monster_imgs *img);

//list
t_item	*ft_lst_creat(int mx, int my);
t_item	*last_lst(t_item *items);
void	ft_lst_add_back(t_item **items, t_item *new_item);
void	create_item(int mx, int my, t_item **items);

// parsing
int		parsing(int ac, char *filename);
int		check_map_size(int *s);
char	**ft_read_map(int fd);
int		*check_all_rows_size(char **map);
int		check_top_and_bottom(char *top, char *bottom);
int		check_sides(char **map, int width);
int		check_borders(char **map, int *sizes);

// check_valid_path
char	**ft_tab_dup(char **tab);
void	fill_all_paths(char **map, int x, int y);
int		check_all_coins_and_exit_access(char **map);
void	ft_free(char **tabs);
int		check_for_valid_path(char **map, int start_x, int start_y);

#endif