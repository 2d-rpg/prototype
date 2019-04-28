#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "stb_image.h"
#include "game.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Game::Game(GLuint width, GLuint height) : state(GAME_MAIN_MENU), keys(), width(width), height(height){ }
