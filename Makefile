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
LDFLAGS	+=	-L ./lib -l graphics -l csfml-graphics \
-l csfml-window -l csfml-system -l button -l my
LD_PRELOAD	=

NAME    =   my_rpg

all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

debug: CFLAGS += $(DEBUG)
debug: LIB_COMPILE += debug
debug: $(NAME)
redebug: fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LIB_COMPILE += sanitize
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: $(NAME)
resanitize: fclean sanitize

make_libs:
	$(MAKE) -C lib/my/ $(LIB_COMPILE)
	$(MAKE) -C lib/my_graphics $(LIB_COMPILE)
	$(MAKE) -C lib/button $(LIB_COMPILE)

$(NAME): make_libs $(OBJ)
	@echo -------------
	@echo CC : $(CC)
	@echo CFLAGS : $(CFLAGS)
	@echo LDFLAGS : $(LD_PRELOAD) $(LDFLAGS)
	@gcc $(OBJ) $(LD_PRELOAD) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "$< -> $@"
	@$(CC) -c $(CFLAGS) -I ./include/ $< -o $@

clean_libs:
	$(MAKE) -C ./lib/my/ clean
	$(MAKE) -C ./lib/my_graphics clean
	$(MAKE) -C ./lib/button clean

clean: clean_libs
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)

fclean_libs:
	$(MAKE) -C ./lib/my/ fclean
	$(MAKE) -C ./lib/my_graphics fclean
	$(MAKE) -C ./lib/button fclean

fclean: clean fclean_libs
	@rm -f $(NAME)
