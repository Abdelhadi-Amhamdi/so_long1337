





all:
	@gcc -g draw_map.c read_map.c so_long.c gnl/get_next_line.c gnl/get_next_line_utils.c -lmlx -framework OpenGL -framework AppKit libft/ft_split.c libft/ft_strjoin.c libft/ft_memcpy.c libft/ft_substr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_memset.c mouves.c