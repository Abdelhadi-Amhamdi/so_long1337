/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:24:21 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 16:40:32 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct so_long
{
    void *mlx;
    void *mlx_win;
    int width;
    int heigth;

} to_long;

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
} t_img;

typedef struct s_data
{
    struct s_img *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;