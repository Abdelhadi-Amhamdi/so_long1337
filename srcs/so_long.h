/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 16:46:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int	x;
	int	y;
}	t_player;

typedef struct s_images
{
	void	*wr;
	void	*wl;
	void	*wt;
	void	*wb;
	void	*pr;
	void	*pl;
	void	*pt;
	void	*pc;
	void	*c;
	void	*bg;
	void	*bc;
	void	*e;
	void	*eo;
}	t_image;

typedef struct so_long
{
	void		*mlx;
	void		*mlx_w;
	int			win_w;
	int			win_h;
	int			e_x;
	int			e_y;
	int			collects;
	char		**map;
	t_item		*coins;
	t_player	*p;
	t_image		*img;
	int			s;
}	t_long;

// read map
char	**read_map(char *map_file);

// draw map
void	ft_draw_map(t_long *game);
void	ft_put_end_screen(t_long *game, char type);
void	end_game(char type, t_long *game);
void	ft_draw_background(t_long *game, t_image *img, int x, int y);
void	ft_draw_walls(t_long *game, t_image *img, int x, int y);
void	draw_components(char c, t_long *game, int x, int y);

//mouves
int		move_player(int keycode, t_long *game);
void	handle_coins(t_long *g, int x, int y, char c);
void	ft_move_right(t_long *g);
void	ft_move_left(t_long *g);
void	ft_move_top(t_long *g);
void	ft_move_buttom(t_long *g);
int		ft_close(int keycode, t_long *game, t_image *images);

//parsing
int		check_valid_path(t_long *game);
int		check_access_to_coins_and_player(char **map);

// init images
void	ft_init_images(t_long *game, t_image *images);

// utils
char	get_val(int x, int y, t_long *game);
void	set_val(t_long *game, int x, int y, char c);
int		ft_str_tablen(char **tabs);
void	calc_window_size(t_long *game);
char	**ft_tabdup(char **map);
void	ft_calc_sizes(int *w, int *h, t_long *g);

#endif