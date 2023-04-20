##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

SRC = 	src/main.c							\
		src/init_g_src.c					\
		src/menu.c							\
		src/settings.c						\
		src/core.c 							\
		src/pause_menu.c					\
		src/event.c							\
		src/manage_mouse.c					\
		src/button.c						\
		src/sliding_button.c				\
		src/button_append.c					\
		src/button_interactions.c			\
		src/init_character.c				\
		src/inventory.c						\
		src/save.c							\
		src/free.c							\
		src/crowd.c 						\
		src/progress_bar.c 					\
		src/rand.c							\
		src/init_crowd.c 					\
		src/update_cop.c 					\
		src/update_mob.c 					\
		src/update.c						\
		src/character_menu/character_menu.c	\
		src/character_menu/init_free.c		\
		src/character_menu/shrink_window.c

OBJ =   $(SRC:.c=.o)

CC  =   gcc
DEBUG   =   -g3 -p -ggdb3 -DDEBUG_MODE

# To prevent Marvin from flagging my code due to optimizations
RELEASE = -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined

CFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char       \
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -fms-extensions
LDFLAGS	+=	-L ./lib -l graphics -l csfml-graphics \
-l csfml-window -l csfml-system -l csfml-audio -l button -l my -l audio -lm
LD_PRELOAD	=

NAME    =   my_rpg

.PHONY: all re debug redebug sanitize resanitize make_libs \
lean_libs clean fclean
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
	@$(MAKE) -s -j -C lib/my/ $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/my_graphics $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/button $(LIB_COMPILE)
	@$(MAKE) -s -j -C lib/audio $(LIB_COMPILE)

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
	@$(MAKE) -s -j -C ./lib/my/ clean
	@$(MAKE) -s -j -C ./lib/my_graphics clean
	@$(MAKE) -s -j -C ./lib/button clean
	@$(MAKE) -s -j -C ./lib/audio clean

clean: clean_libs
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)

fclean_libs:
	@$(MAKE) -s -j -C ./lib/my/ fclean
	@$(MAKE) -s -j -C ./lib/my_graphics fclean
	@$(MAKE) -s -j -C ./lib/button fclean
	@$(MAKE) -s -j -C ./lib/audio fclean

fclean: clean fclean_libs
	@rm -f $(NAME)
