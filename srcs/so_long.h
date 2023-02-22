/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:27 by aamhamdi         ###   ########.fr       */
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
	void	*w;
	void	*pr;
	void	*pl;
	void	*p;
	void	*c;
	void	*bg;
	void	*ex;
	void	*eo;
}	t_image;

typedef struct so_long
{
	void		*mlx;
	void		*mlx_win;
	int			win_w;
	int			win_h;
	int			exit_x;
	int			exit_y;
	int			collects;
	char		**map;
	t_item		*coins;
	t_player	*player;
	t_image		*images;
	int			s;
}	t_long;

char	**read_map(char *map_file);
void	ft_draw_map(t_long *game);
int		move_player(int keycode, t_long *game);
void	ft_init_images(t_long *game, t_image *images);
char	get_val(int x, int y, t_long *game);
void	set_val(t_long *game, int x, int y, char c);

void	ft_put_end_screen(t_long *game, char type);
int		ft_str_tablen(char **tabs);
void	calc_window_size(t_long *game);

int		check_valid_path(t_long *game);
int		ft_str_tablen(char **tabs);
void	end_game(char type, t_long *game);
#endif