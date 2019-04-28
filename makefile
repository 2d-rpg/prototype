# Recursive wildcard
rwildcard = $(foreach d, $(wildcard $1*), $(call rwildcard, $d/, $2) $(filter $(subst *, %, $2), $d))

# Options
CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -lglfw3 -lGL -lXrandr -lXinerama -lXcursor -lXi -lXxf86vm -lX11 -lpthread -lrt -lm -ldl
INCLUDE_DIRECTORY = include
SOURCE_DIRECTORY = src
OBJECT_FILE_DIRECTORY = obj
BUILD_DIRECTORY = build
BINARY_FILE_DIRECTORY = bin
EXECUTABLE_FILE_NAME = 2D_GAME
RESOURCES_DIRECTORY = resources

# Usefil variables
SOURCES := $(call rwildcard , $(SOURCE_DIRECTORY), *.c *.cpp)
INCLUDE := -I $(INCLUDE_DIRECTORY)
INCLUDES := $(call rwildcard , $(INCLUDE_DIRECTORY), *.h *.hpp)
OBJECT0 := $(patsubst %.cpp, %.o, $(SOURCES))
OBJECT1 := $(patsubst %.c, %.o, $(OBJECT0))
OBJECT_FILES := $(patsubst $(SOURCE_DIRECTORY)/%, $(OBJECT_FILE_DIRECTORY)/%, $(OBJECT1))
REQUIRED_DIRECTORIES := $(dir $(OBJECT_FILES))

.PHONY: clean

all: $(REQUIRED_DIRECTORIES) $(EXECUTABLE_FILE_NAME) run

compile: $(REQUIRED_DIRECTORIES) $(EXECUTABLE_FILE_NAME)

build: $(REQUIRED_DIRECTORIES) $(EXECUTABLE_FILE_NAME)
	@mkdir -p $(BUILD_DIRECTORY) $(BUILD_DIRECTORY)/$(BINARY_FILE_DIRECTORY) $(BUILD_DIRECTORY)/$(RESOURCES_DIRECTORY)
	@cp $(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME) $(BUILD_DIRECTORY)/$(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)
	@cp -r $(RESOURCES_DIRECTORY) $(BUILD_DIRECTORY)/$(RESOURCES_DIRECTORY)

run:
	@./$(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)

%/:
	@mkdir -p $@

$(EXECUTABLE_FILE_NAME): $(OBJECT_FILES)
	@mkdir -p $(BINARY_FILE_DIRECTORY)
	@echo "=============================================="
	@echo "Compiling executable --> $(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)"
	@$(CC) -o $(BINARY_FILE_DIRECTORY)/$@ $^ $(CFLAGS)
	@echo "=============================================="

$(OBJECT_FILE_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.cpp
	@mkdir -p $(OBJECT_FILE_DIRECTORY)
	@echo "=============================================="
	@echo "Compiling object file --> $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "=============================================="

$(OBJECT_FILE_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	@echo "=============================================="
	@echo "Compiling object file --> $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "=============================================="

stage:
	git add $(INCLUDE_DIRECTORY) $(SOURCES) makefile $(RESOURCES_DIRECTORY)

clean:
	rm -r $(OBJECT_FILE_DIRECTORY) $(BINARY_FILE_DIRECTORY) $(BUILD_DIRECTORY)
