
NAME=so_long
BONUS_NAME=so_long_bonus



all: $(NAME)
	

$(NAME):
	@gcc srcs/draw_map.c srcs/mouves.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c  srcs/read_map.c libft/ft_putendl_fd.c  srcs/check_path.c  srcs/so_long.c srcs/utills.c gnl/get_next_line.c gnl/get_next_line_utils.c -lmlx -framework OpenGL -framework AppKit libft/ft_split.c libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_substr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_memset.c -o $@

bonus: clean
	@gcc bonus/draw_map_bonus.c bonus/mouves_bonus.c bonus/draw_functions.c  bonus/read_map_bonus.c bonus/so_long_bonus.c bonus/utills_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c -lmlx -framework OpenGL -framework AppKit libft/ft_split.c libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_substr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_memset.c -o $(BONUS_NAME)

clean:
	rm -rf $(NAME) $(BONUS_NAME)

re: clean all