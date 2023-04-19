##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= \
button_draw.c \
button_free.c \
button_init.c \
button_misc.c \
button_title.c

OBJ	=	$(SRC:.c=.o)

CC 	=	gcc
DEBUG	=	-g3 -p -ggdb3
# Prevents GCC optimizations
RELEASE =  -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fno-sanitize-recover=address,undefined

CFLAGS	+=	-Wall -Wextra -pedantic -fsigned-char		\
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -pedantic

NAME	=	../libbutton.a

all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: $(NAME)
resanitize: fclean sanitize

link_header: button.h
	@echo Linking header
	@ln -f button.h ../../include/button.h

$(NAME): link_header $(OBJ)
	@echo Building lib button...
	@ar rcs $(NAME) $(OBJ)

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
