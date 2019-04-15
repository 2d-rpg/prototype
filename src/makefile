# Options
CC=g++
CFLAGS=-std=c++11 -lglfw3 -lGL -lXrandr -lXinerama -lXcursor -lXi -lXxf86vm -lX11 -lpthread -lrt -lm -ldl
DEPS=glad.c

build: 2D_RPG.cpp $(DEPS)
	@$(CC) -o 2D_RPG 2D_RPG.cpp glad.c $(CFLAGS) || (echo "Failed to build program. Exit status: $$?"; exit 1)
	@echo "===========< Compilation success! >==========="
	@echo "===========< Program output below. >=========="
	@./2D_RPG || (echo "Program exited with error. Exit status: $$?"; exit 1)

% : %.cpp $(DEPS)
	@$(CC) -o $@ $(DEPS) $< $(CFLAGS) || (echo "Failed to build program. Exit status: $$?"; exit 1)
	@echo "===========< Compilation success! >==========="
	@echo "===========< Program output below. >=========="
	@./$@ || (echo "Program exited with error. Exit status: $$?"; exit 1)
