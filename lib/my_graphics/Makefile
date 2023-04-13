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
			draw/switch_draw_show.c		\
			draw/swap_draw.c			\
			draw/sort_draws.c			\
			draw/draw_single_draw.c		\
			draw/draw_draws.c			\
			draw/free_single_draw.c		\
			draw/free_draws.c			\
			shape/init_shape.c			\
			shape/create_shape.c		\
			shape/set_pos_shape.c		\
			shape/set_size_shape.c		\
			shape/set_angle_shape.c		\
			shape/set_data_shape.c		\
			shape/draw_shape.c			\
			shape/free_shape.c			\
			sprite/init_sprite.c		\
			sprite/set_pos_sprite.c		\
			sprite/set_scale_sprite.c	\
			sprite/set_angle_sprite.c	\
			sprite/set_data_sprite.c	\
			sprite/set_texture_sprite.c	\
			sprite/set_anim_sprite.c	\
			sprite/draw_sprite.c		\
			sprite/free_sprite.c		\
			text/init_text.c			\
			text/create_text.c			\
			text/set_pos_text.c			\
			text/set_size_text.c		\
			text/set_angle_text.c		\
			text/set_data_text.c		\
			text/set_color_text.c		\
			text/set_font_text.c		\
			text/set_string_text.c		\
			text/draw_text.c			\
			text/free_text.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libgraphics.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc -l"csfml-graphics csfml-system" $(NAME) $(OBJ)
	@cp $(NAME) ../

%.o:%.c
	@gcc -c -Wall -Wextra $< -o $@

clean:
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f *.out
	@rm -f coding-style-reports.log
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re: fclean all
