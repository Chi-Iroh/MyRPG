all:
	@echo "make progress_bar to build an example of a progress bar controlled by mouse scroll."

make_libs:
	@$(MAKE) -C ../../lib/my/

progress_bar:
	gcc progress_bar.c -lcsfml-graphics -lcsfml-window -lcsfml-system -L ../../lib/ -lmy -std=gnu2x -o progress_bar -O2 -Wall -Wextra

clean:
	@echo Removing binary.
	@rm -f progress_bar
