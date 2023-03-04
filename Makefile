# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 12:10:58 by yjaadoun          #+#    #+#              #
#    Updated: 2023/03/04 17:28:53 by yjaadoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub.c

NAME = cub3D

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -D

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ =  $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make all
	@$(CC) $(C_FLAGS) $(MLX_FLAGS) libft/libft.a $(OBJ) -o $(NAME)

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