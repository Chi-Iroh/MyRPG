##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-adrien.audiard
## File description:
## Makefile
##

NAME = push_swap

SRC	=	$(wildcard ./source/*.c) $(wildcard ./bonus/*.c)
CFLAGS	=	-g3
OBJ	=	$(SRC:.c=.o)

LIB	=	lib$(NAME).a

all:	$(LIB)

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)
	gcc main.c -o $(NAME) $(CFLAGS) -L. -l$(NAME) -lncurses -I include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

cpl: re
	make clean

run: cpl
	./$(NAME)
