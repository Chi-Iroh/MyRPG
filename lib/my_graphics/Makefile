##
## EPITECH PROJECT, 2023
## my_graphics
## File description:
## Makefile
##

SRC		=	vector/set_vector.c			\
			vector/increment_vector.c	\
			vector/scale_vector.c		\
			window/init_window.c		\
			window/create_window.c		\
			window/actualize_window.c	\
			window/view.c				\
			window/free_window.c		\
			layer/init_layer.c			\
			layer/create_layer.c		\
			layer/switch_layer_show.c	\
			layer/swap_layer.c			\
			layer/draw_single_layer.c	\
			layer/draw_layers.c			\
			layer/free_single_layer.c	\
			layer/free_layers.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_graphics.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc -l"csfml-graphics csfml-system" $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.out
	rm -f coding-style-reports.log
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
