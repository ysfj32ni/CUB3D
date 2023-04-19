# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 12:10:58 by yjaadoun          #+#    #+#              #
#    Updated: 2023/04/13 15:14:45 by yjaadoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub.c \
	parsing/cub_utiles1.c \
	parsing/map_elements.c \
	parsing/map.c \
	parsing/reading_map.c \
	parsing/errors_handler.c \
	parsing/parisng.c \
	parsing/textures.c \
	parsing/colores.c \
	drawing/2d_map.c \
	drawing/mlx_functions.c \
	drawing/window.c \
	drawing/player_movements.c \
	drawing/cast_rays.c \

	
NAME = cub3D

CC = cc -g3

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make all
	@$(CC) $(CFLAGS) $(MLX_FLAGS) libft/libft.a $(OBJ) -o $(NAME)

clean: 
	@cd libft && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all
	
git :
	git add .
	git commit -m "CUB3D_dailly_work"
	git push
