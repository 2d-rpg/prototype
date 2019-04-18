# Options
CC=g++
CFLAGS=-std=c++11 -lglfw3 -lGL -lXrandr -lXinerama -lXcursor -lXi -lXxf86vm -lX11 -lpthread -lrt -lm -ldl
DEPS=glad.c shader.cpp utils.cpp stb_image.cpp texture_2D.cpp sprite_loader.cpp

build: 2D_RPG.cpp $(DEPS)
	@$(CC) -o ../bin/2D_RPG 2D_RPG.cpp glad.c $(CFLAGS) || (echo "Failed to build program. Exit status: $$?"; exit 1)
	@echo "===========< Compilation success! >==========="
	@echo "===========< Program output below. >=========="
	@../bin/2D_RPG || (echo "Program exited with error. Exit status: $$?"; exit 1)

% : %.cpp $(DEPS)
	@$(CC) -o ../bin/$@ $(DEPS) $< $(CFLAGS) || (echo "Failed to build program. Exit status: $$?"; exit 1)
	@echo "===========< Compilation success! >==========="
	@echo "===========< Program output below. >=========="
	@../bin/$@ || (echo "Program exited with error. Exit status: $$?"; exit 1)

stage:
	@git add ../src ../resources
