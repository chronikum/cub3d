# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 16:37:58 by jfritz            #+#    #+#              #
#    Updated: 2022/04/10 15:32:26 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Conditional
GET_OS := $(shell uname -s)

ifeq ($(GET_OS), Darwin)
	OS			=		macOS
	mlxpath		=		./minilibx_macos
else
	OS			=		Linux
	mlxpath		=		./minilibx_linux
endif

CC = gcc

NAME = cub3d

ENTRY = ./src/main.c

PARSING =	./src/parsing/identifiers.c \
			./src/parsing/lst.c \
			./src/parsing/map.c \
			./src/parsing/parser.c \
			./src/parsing/spawn_player.c \
			./src/parsing/spawn_player_direction.c

GNL		=	./src/gnl/get_next_line.c \
			./src/gnl/get_next_line_utils.c

UTILS =		./src/utils/build_charmap.c \
			./src/utils/put_pixel.c \
			./src/utils/create_vector2.c \
			./src/utils/ternary_helper.c

CONTROLS = ./src/controls/keyhandler.c

CLEARDATA =	./src/clear_data/clear_data.c

RENDERING =	./src/rendering/render_preparing.c \
			./src/rendering/render_walls.c \
			./src/rendering/draw_line_color.c \
			./src/textures/shading.c \
			./src/rendering/render_wall_helper.c \
			./src/rendering/mlx_helper.c

TEXTURES =	./src/textures/textures.c \
			./src/textures/new_texture.c \
			./src/textures/fill_floor_ceiling.c \
			./src/textures/get_texture_direction.c
			
CACHE	=	./src/cache/player_cache.c

MINIMAP	=	./src/minimap/minimap.c

MOVEMENT	=	./src/movement/movement.c \
				./src/movement/rotation.c


FRAMES_PER_SECOND = ./src/utils/frames_per_second.c


SRCS = $(PARSING) $(CACHE) $(MOVEMENT) $(MINIMAP) $(RENDERING) $(TEXTURES) $(CONTROLS) $(CLEARDATA) $(GNL) $(UTILS) $(ENTRY)

BONUS = $(FRAMES_PER_SECOND)

PRINT_HEADER	=		echo "                     ";echo "			         _   ___   _ ";echo "			 ___ _ _| |_|_  |_| |";echo "			|  _| | | . |_  | . |";echo "			|___|___|___|___|___|";echo "                     ";

OBJS			=		$(SRCS:.c=.o)

BONUSO			=		$(BONUS:.c=.o)

LIB				=		@make -C ./libft

MLX				=		@make -C $(mlxpath)

CFLAGS			=		-Wall -Werror -Wextra -g

DEBUG			=		-g -fsanitize=address

MLXFLAGS		=		-framework OpenGL -framework AppKit

.c.o			:
						@gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)			:		$(OBJS)
						@$(PRINT_HEADER)
						$(LIB)
						@echo "$(Cyan)Libft 100%$(Set_Color)"
						$(MLX)
						@echo "$(Yellow)MinilibX 100%$(Set_Color)"
						@gcc $(CFLAGS) $(OBJS) libft/libft.a $(mlxpath)/libmlx.a $(MLXFLAGS) -o $(NAME)
						@echo "$(Green)Cub3d for $(OS) has been created$(Set_Color)"

bonus			:		$(OBJS) $(BONUSO)
						@$(PRINT_HEADER)
						$(LIB)
						@echo "$(Cyan)Libft 100%$(Set_Color)"
						$(MLX)
						@echo "$(Yellow)MinilibX 100%$(Set_Color)"
						@gcc $(CFLAGS) $(OBJS) libft/libft.a $(mlxpath)/libmlx.a $(MLXFLAGS) -o $(NAME)
						@echo "$(Green)Cub3d for $(OS) has been created$(Set_Color)"

devmode			:		$(OBJS)
						$(LIB)
						@echo "$(Red)YOU ARE COMPILING WITHOUT FLAGS! YOU ARE COMPILING WITHOUT FLAGS! YOU ARE COMPILING WITHOUT FLAGS!$(Set_Color)"
						@echo "$(Cyan)Libft 100%$(Set_Color)"
						$(MLX)
						@echo "$(Yellow)MinilibX 100%$(Set_Color)"
						@gcc $(CFLAGS) $(DEBUG) $(OBJS) libft/libft.a $(mlxpath)/libmlx.a $(MLXFLAGS) -o $(NAME)
						@echo "$(Green)Cub3d for $(OS) has been created$(Set_Color)"
						@echo "$(Red)YOU ARE COMPILING WITHOUT FLAGS! YOU ARE COMPILING WITHOUT FLAGS! YOU ARE COMPILING WITHOUT FLAGS!$(Set_Color)"

lib				:
						$(LIB)
						@echo "$(Cyan)Libft 100%$(Set_Color)"

mlx				:
						$(MLX)
						@echo "$(Yellow)MinilibX 100%$(Set_Color)"

clean			:
						@rm -f $(OBJS)
						@echo "$(Red)Objects removed$(Set_Color)"

libclean			:
						@cd ./libft && make fclean
						@echo "$(Red)Libft removed$(Set_Color)"

mlxclean			:
						@cd $(mlxpath) && make clean
						@echo "$(Red)MinilibX removed$(Set_Color)"

fclean			:		clean libclean
						@rm -f $(NAME)
						@echo "$(Red)Cub3d has been removed$(Set_Color)"

all				:		$(NAME)

bonus			:		all

re				:		fclean all

.PHONY			:		clean fclean all re bonus
