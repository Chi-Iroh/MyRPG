##
## EPITECH PROJECT, 2023
## libgraphics
## File description:
## Makefile
##

SRC		=	vector/set_vector.c			\
			vector/increment_vector.c	\
			vector/scale_vector.c		\
			rect/set_rectangle.c		\
			rect/next_rectangle.c		\
			window/init_window.c		\
			window/create_window.c		\
			window/splash.c				\
			window/actualize_window.c	\
			window/append_layer.c		\
			window/view.c				\
			window/free_window.c		\
			layer/init_layer.c			\
			layer/create_layer.c		\
			layer/switch_layer_show.c	\
			layer/swap_layer.c			\
			layer/append_draw_layer.c	\
			layer/draw_single_layer.c	\
			layer/draw_layers.c			\
			layer/free_single_layer.c	\
			layer/free_layers.c			\
			data/init_data.c			\
			data/create_data.c			\
			data/set_depth.c			\
			data/set_pos_data.c			\
			data/set_size_data.c		\
			data/set_angle_data.c		\
			data/set_data.c				\
			draw/init_draw.c			\
			draw/create_draw.c			\
			draw/set_data_draw.c		\
			draw/set_attributes_draw.c	\
			draw/set_string_draw.c		\
			draw/set_animation_draw.c	\
			draw/set_origin_draw.c		\
			draw/get_data_draw.c		\
			draw/modify_draw.c			\
			draw/get_global_bounds_draw.c	\
			draw/switch_draw_show.c		\
			draw/swap_draw.c			\
			draw/sort_draws.c			\
			draw/draw_single_draw.c		\
			draw/draw_draws.c			\
			draw/free_single_draw.c		\
			draw/free_draws.c			\
			shape/init_shape.c			\
			shape/create_shape.c		\
			shape/set_data_shape.c		\
			shape/set_attributes_shape.c	\
			shape/get_data_shape.c		\
			shape/modify_shape.c		\
			shape/draw_shape.c			\
			shape/free_shape.c			\
			sprite/init_sprite.c		\
			sprite/set_data_sprite.c	\
			sprite/set_animation_sprite.c	\
			sprite/get_data_sprite.c		\
			sprite/modify_sprite.c			\
			sprite/set_texture_sprite.c	\
			sprite/draw_sprite.c		\
			sprite/free_sprite.c		\
			text/init_text.c			\
			text/create_text.c			\
			text/set_data_text.c		\
			text/set_attributes_text.c	\
			text/set_string_text.c		\
			text/get_data_text.c		\
			text/modify_text.c			\
			text/set_font_text.c		\
			text/set_string_text.c		\
			text/draw_text.c			\
			text/free_text.c			\
			background/my.c				\
			background/tmx.c			\
			background/parser_csv.c		\
			background/parser_tmx.c		\
			background/create_background.c

OBJ	=	$(SRC:.c=.o)

CC 	=	gcc
DEBUG	=	-g3 -p -ggdb3
# Prevents GCC optimizations
RELEASE =  -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined

CFLAGS	+=	-Wall -Wextra -pedantic -fsigned-char		\
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -pedantic

NAME	=	../libgraphics.a

all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: $(NAME)
resanitize: fclean sanitize

$(NAME): $(OBJ)
	@echo Building lib graphics...
	@ar rc -l"csfml-graphics csfml-system" $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@

clean:
	@echo "[LIB] Removing temporary and object files."
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@rm -f ../../include/button.h

fclean: clean
	@echo "[LIB] Removing binary."
	@rm -f ../$(NAME)
