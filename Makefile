##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

SRC = 	src/main.c	\
		src/save.c

OBJ =   $(SRC:.c=.o)

CC  =   gcc
DEBUG   =   -g3 -p -ggdb3 -DDEBUG_MODE

# To prevent Marvin from flagging my code due to optimizations
RELEASE = -O0 -fno-builtin
SANITIZE    =   -fsanitize=address,undefined

CFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char       \
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -fms-extensions

NAME    =   my_rpg

all: CFLAGS += $(RELEASE)
all: | $(NAME)
re: | fclean all

debug: CFLAGS += $(DEBUG)
debug: LIB_COMPILE += debug
debug: | $(NAME)
redebug: | fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LIB_COMPILE += sanitize
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: | $(NAME)
resanitize: | fclean sanitize

make_libs:
	$(MAKE) -C lib/my/
	$(MAKE) -C lib/my_graphics

$(NAME): | make_libs $(OBJ)
	@echo -------------
	@echo CC : $(CC)
	@echo CFLAGS : $(CFLAGS)
	@if [ -d "./lib/" ]; then												\
		gcc $(OBJ) $(LD_PRELOAD) -o $(NAME); 								\
	else  																	\
		gcc $(OBJ) $(LD_PRELOAD) -o $(NAME); 								\
	fi

%.o: %.c
	@echo "$< -> $@"
	@$(CC) -c $(CFLAGS) -I ./include/ $< -o $@

clean:
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

test: fclean $(OBJ)
	cd ./lib/my_graphics && make re
	gcc $(OBJ) -L ./lib -l graphics -l csfml-graphics -l csfml-system -o $(NAME)
