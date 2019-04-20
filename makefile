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
# SOURCES := $(wildcard $(SOURCE_DIRECTORY)/*.cpp)
INCLUDE := -I $(INCLUDE_DIRECTORY)
INCLUDES := $(shell find $(INCLUDE_DIRECTORY) \( -name '*.h' -o -name '*.hpp' \))
# OBJECT_FILES := $(shell find $(OBJECT_FILE_DIRECTORY) -name '*o')
OBJECT0 := $(patsubst %.cpp, %.o, $(SOURCES))
OBJECT1 := $(patsubst %.c, %.o, $(OBJECT0))
# OBJECT_FILES := $(patsubst $(SOURCE_DIRECTORY)/*, $(OBJECT_FILE_DIRECTORY)/*, $(OBJECT1))
OBJECT_FILES := $(patsubst $(SOURCE_DIRECTORY)/%, $(OBJECT_FILE_DIRECTORY)/%, $(OBJECT1))
REQUIRED_DIRECTORIES := $(dir $(OBJECT_FILES))

all: run $(REQUIRED_DIRECTORIES) $(EXECUTABLE_FILE_NAME)

compile: $(EXECUTABLE_FILE_NAME)

run:
	@$(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)

%/:
	@mkdir -p $@

$(EXECUTABLE_FILE_NAME): $(OBJECT_FILES)
	@echo "=============================================="
	@echo "Compiling executable --> $(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)"
	@$(CC) -o $(BINARY_FILE_DIRECTORY)/$@ $^ $(CFLAGS)
	@echo "=============================================="

$(OBJECT_FILE_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.cpp
	@echo "=============================================="
	@echo "Compiling object file --> $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "=============================================="

$(OBJECT_FILE_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	@echo "=============================================="
	@echo "Compiling object file --> $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "=============================================="

# all: $(SOURCES) $(INCLUDES)
# 	@ if [! -d $(OBJECT_FILE_DIRECTORY) ]; \
# 		then mkdir -p $(OBJECT_FILE_DIRECTORY); \
# 		fi
# 	@ if [! -d $(BINARY_FILE_DIRECTORY) ]; \
# 		then mkdir -p $(BINARY_FILE_DIRECTORY); \
# 		fi
# 	@$(CC) -o $(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME) $(INCLUDE)  $(SOURCES) $(CFLAGS) || exit 1
# 	@$(BINARY_FILE_DIRECTORY)/$(EXECUTABLE_FILE_NAME)

stage:
	git add $(INCLUDE_DIRECTORY) $(SOURCES) makefile $(RESOURCES_DIRECTORY)

test:
	echo $(OBJECT_FILES)
	echo $(REQUIRED_DIRECTORIES)

.PHONY: clean

clean:
	@find $(OBJECT_FILE_DIRECTORY) -name '*o' -exec rm {} \;
