# Options
CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -lglfw3 -lGL -lXrandr -lXinerama -lXcursor -lXi -lXxf86vm -lX11 -lpthread -lrt -lm -ldl
INCLUDE_DIRECTORY = ./include
SOURCE_DIRECTORY = ./src
OBJECT_FILE_DIRECTORY = ./obj
BUILD_DIRECTORY = ./build
BINARY_FILE_DIRECTORY = ./bin
EXECUTABLE_FILE_NAME = 2D_GAME
RESOURCES_DIRECTORY = ./resources

# Usefil variables
SOURCES := $(shell find $(SRC) \( -name '*.cpp' -o -name '*.c' \))
INCLUDE := -I $(INCLUDE_DIRECTORY)
INCLUDES := $(shell find $(INCLUDE_DIRECTORY) \( -name '*.h' -o -name '*.hpp' \))
OBJECT_FILES := $(shell find $(OBJECT_FILE_DIRECTORY) -name '*o')

all: $(SOURCES) $(INCLUDES)
	@$(CC) -o $(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME) $(INCLUDE)  $(SOURCES) $(CFLAGS) || exit 1
	@$(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

stage:
	git add $(INCLUDE_DIRECTORY) $(SOURCES) makefile $(RESOURCES_DIRECTORY)

test:
	echo $(OBJECT_FILES)
