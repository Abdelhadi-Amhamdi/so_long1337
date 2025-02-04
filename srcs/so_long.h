/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 13:17:00 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

# define INVALID_ARGS_NUMBER "Error\nexpected 1 args 0 or more founded"
# define INVLIDE_MAP_NAME "Error\nexpected .ber map format"
# define INVALID_FILE "Error\nfile does not exist"
# define INVALID_MAP_SIZE "Error\ninvalid map size"
# define INVALID_MAP_STRUCTURE "Error\ninvalid map structure"
# define PLAYER_ERROR "Error\nplayer not founded or more than one"
# define EXIT_ERROR "Error\nexit not founded or more than one"
# define COINS_ERROR "Error\nat least one collectable required"

typedef struct s_players
{
	int	x;
	int	y;
}	t_player;

typedef struct s_parsing_items
{
	int	p;
	int	e;
	int	c;
	int	rows;
	int	index;
}	t_parsing_items;

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
	t_player	*p;
	t_image		*img;
	int			s;
}	t_long;

char	**ft_read_map(int fd);

void	ft_draw_map(t_long *game);
void	ft_close_window(t_long *game, char action);
void	end_game(char type, t_long *game);
void	ft_draw_background(t_long *game, t_image *img, int x, int y);
void	ft_draw_walls(t_long *game, t_image *img, int x, int y);
void	draw_components(char c, t_long *game, int x, int y);

int		move_player(int keycode, t_long *game);
void	handle_coins(t_long *g, char c);
void	ft_move_right(t_long *g, int *mouves);
void	ft_move_left(t_long *g, int *mouves);
void	ft_move_top(t_long *g, int *mouves);
void	ft_move_buttom(t_long *g, int *mouves);

int		check_valid_path(t_long *game);
int		check_access_to_coins_and_player(char **map);
char	**parsing(int ac, char *filename);
int		check_map_size(int *s);
int		*check_all_rows_size(char **map);
int		check_top_and_bottom(char *top, char *bottom);
int		check_sides(char **map, int width);
int		chaeck_valid_map_name(const char *file_name);
int		check_borders(char **map, int *sizes);
int		check_map_structure(char **map);
int		check_items(char **map);
int		check_map_items(char **map, t_parsing_items *items);
void	ft_free(char **data);
void	ft_print_error(int status);

int		ft_init_images(t_long *game, t_image *img);

char	get_val(int x, int y, t_long *game);
void	set_val(t_long *game, int x, int y, char c);
int		ft_str_tablen(char **tabs);
void	calc_window_size(t_long *game);
char	**ft_tabdup(char **map);
void	get_player_position(t_long *game);

#endif