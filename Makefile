# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 22:34:29 by aamhamdi          #+#    #+#              #
#    Updated: 2023/03/08 19:17:14 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = so_long
BONUS_NAME = so_long_bonus

M_PATH     = srcs/
B_PATH     = bonus/
G_PATH     = gnl/
OBJ_PATH   = build/
LIBFT_PATH = libft/

SRCS_H  = so_long.h
SRCSB_H = so_long_bonus.h
LIBFT_H = libft.h
GNL_H   = get_next_line.h

SRC     = draw_map.c parsing.c parsing_utils.c mouves2.c mouves.c read_map.c check_path.c  so_long.c utills.c
SRC_B   = draw_map_bonus.c parsing_utils_bonus.c check_valid_path_bonus.c parsing_bonus.c utils_bonus2.c animation_bonus.c \
mouves_bonus.c draw_functions.c  read_map_bonus.c so_long_bonus.c utills_bonus.c
SRC_G   = get_next_line.c get_next_line_utils.c

SRCS   = $(addprefix $(M_PATH), $(SRC))
SRCS_B = $(addprefix $(B_PATH), $(SRC_B))
SRCS_G = $(addprefix $(G_PATH), $(SRC_G))

OBJ   = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
OBJ_G = $(SRC_G:.c=.o)

OBJS   = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_B = $(addprefix $(OBJ_PATH), $(OBJ_B))
OBJS_G = $(addprefix $(OBJ_PATH), $(OBJ_G))

LIBS  = -lmlx -framework OpenGL -framework AppKit 
LIBFT = libft.a
CC    = cc
FLAGS = -Wall -Wextra -Werror

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(B_PATH)%.c $(B_PATH)$(SRCSB_H)
	$(CC) $(FLAGS) -c $< -o $@
	
$(OBJ_PATH)%.o: $(M_PATH)%.c $(M_PATH)$(SRCS_H)
	$(CC) $(FLAGS) -c $< -o $@
	
$(OBJ_PATH)%.o: $(G_PATH)%.c $(G_PATH)$(GNL_H)
	$(CC) $(FLAGS) -c $< -o $@
	
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(OBJS_G) $(LIBFT)
	@$(CC) $(FLAGS) $(LIBS) $(OBJS) $(OBJS_G) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
	
bonus: $(OBJ_PATH) $(OBJS_B) $(OBJS_G) $(LIBFT) 
	@$(CC) $(FLAGS) $(LIBS) $(OBJS_B) $(OBJS_G) $(LIBFT_PATH)$(LIBFT) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJ_PATH)
	@make clean -s -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	
re: fclean all