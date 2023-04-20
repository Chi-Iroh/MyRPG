##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	= \
audio_init.c \
audio_free.c \
audio_volume.c \
audio_set.c \
audio_control.c

OBJ	=	$(SRC:.c=.o)

CC 	=	gcc
DEBUG	=	-g3 -p -ggdb3
# Prevents GCC optimizations
RELEASE =  -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined

CFLAGS	+=	-Wall -Wextra -pedantic -fsigned-char		\
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x -pedantic

NAME	=	../libaudio.a

all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: $(NAME)
resanitize: fclean sanitize

link_header: audio.h
	@echo [LIB AUDIO] Linking header audio.h
	@ln -f audio.h ../../include/audio.h

$(NAME): link_header $(OBJ)
	@echo Building lib button...
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -I ../../include/ -o $@

clean:
	@echo "[LIB AUDIO] Removing temporary and object files."
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f vgcore.*
	@rm -f *.log
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f ../$(NAME)

fclean: clean
	@echo "[LIB AUDIO] Removing binary."
	@rm -f ../$(NAME)
