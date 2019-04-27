/*
<<<<<<< HEAD
 * 2D_RPG.cpp
 *
 * Copyright 2019 Unknown <shinji@FPRAlienwareM17>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


=======
 * Copyright 2019 2d-rpg Project Team - All Rights Reserved.
 * Written by Jumpei Yoshikawa, Shinji Hoshino and Yasuaki Yoshii
 */

>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
#include <iostream>
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
<<<<<<< HEAD
#include "shader.h"
#include "stb_image.h"
#include "texture_2D.h"
#include "sprite_loader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// window resize callback function
void
framebuffer_size_callback(GLFWwindow * window, int width, int height);

// user input test: Pressing ESC key will close the window
void
processInput(GLFWwindow * window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int
main(int argc, char ** argv)
{
=======
#include <shader/shader.h>
#include <stb/stb_image.h>
#include <texture/texture_2D.h>
#include <sprite/sprite_loader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <renderer/map.h>
#include <chrono>
#include <thread>
#include <vector>
#include <random>

int   pos_x, pos_y;
float speed = 5;

// window resize callback function
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// user input test: Pressing ESC key will close the window
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pos_y -= speed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pos_y += speed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        pos_x -= speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        pos_x += speed;
}

int main() {
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
    // Initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
<<<<<<< HEAD

    GLFWwindow * window = glfwCreateWindow(800, 600, "2D_RPG", NULL, NULL);
=======
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "2D_RPG", NULL, NULL);
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
    if (window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
<<<<<<< HEAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
=======
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
        std::cout << "Failed to initialize GLAD." << std::endl;
        return 1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

<<<<<<< HEAD
    Shader shader("./resources/shaders/vertex/test1.vs", "./resources/shaders/fragment/test1.fs");

    Texture2D texture;
    texture.generate("./resources/sprites/test/test0.jpg");

    Sprite_Loader sprite_loader(shader);

    shader.use();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), static_cast<GLfloat>(600), 0.0f, -1.0f, 1.0f);
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
=======
    RendererMap rm(20, 20);
    rm.add_texture("../resources/images/test/map/floor.gif", 0);
    rm.add_texture("../resources/images/test/map/throne.gif", 1);
    rm.add_texture("../resources/images/test/map/wall.gif", 2);
    rm.add_texture("../resources/images/test/map/treasure.gif", 3);

    std::vector<int> map(20 * 20);
    for (int i = 0; i < 20 * 20; i++) {
        map[i] = rand() % static_cast<int>(3 + 1);
    }
    rm.load_map(map);

>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // render code
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

<<<<<<< HEAD
        sprite_loader.draw(texture, glm::vec2(0, 0), glm::vec2(100, 100), 1.57f, glm::vec3(0.0f, 0.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(100, 0), glm::vec2(100, 100), 1.57f, glm::vec3(0.0f, 1.0f, 0.0f));
        sprite_loader.draw(texture, glm::vec2(0, 100), glm::vec2(100, 100), 1.57f, glm::vec3(1.0f, 0.0f, 0.0f));
        sprite_loader.draw(texture, glm::vec2(100, 100), glm::vec2(300, 300), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(200, 0), glm::vec2(200, 100), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(0, 200), glm::vec2(100, 200), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
=======
        rm.render();
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b

        // check all events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
<<<<<<< HEAD
    }

    glfwTerminate();
    1;

    return 0;
} // main

void
framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
    glViewport(0, 0, width, height);
=======

        rm.set_camera(pos_x, pos_y);

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    glfwTerminate();

    return 0;
}  // main

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
#ifdef __APPLE__  // For Retina display
    glfwGetFramebufferSize(window, &width, &height);
#endif
    glViewport(0, 0, width, height);
    glfwMakeContextCurrent(window);
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
}
