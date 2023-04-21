# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glamy <glamy@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 09:25:39 by glamy             #+#    #+#              #
#    Updated: 2020/11/30 08:21:09 by glamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC_NAME = cub3d.c error.c get_next_line.c init.c key.c map.c move.c param.c parse_setup.c raycast.c run.c texture.c utils.c parse_map.c check_all_setup.c sprite.c raycast_spr.c screenshot.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<


SCREENSHOT = screenshot.bmp

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror -fsanitize=address

LIBFT	= libft.a

LIBMLX	= libmlx.dylib

MLX	= -framework OpenGL -framework Appkit

LIBS	= -L./lib/libft -lft -L./lib/mlx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o  $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)


$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C lib/mlx
	cp ./lib/mlx/$(LIBMLX) ./

clean	:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/mlx clean
	rm -rf ./$(LIBMLX) 
	rm -rf $(OBJ_PATH) $(SCREENSHOT)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
