/*
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


#include <iostream>
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
#include "shader.h"
#include "stb_image.h"
#include "texture_2D.h"
#include "sprite_loader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "renderer_map.h"
#include <chrono>
#include <thread>
#include <vector>
#include <random>
#include "text_renderer.h"

int pos_x, pos_y;
float speed = 5;

// window resize callback function
void
framebuffer_size_callback(GLFWwindow * window, int width, int height);

// user input test: Pressing ESC key will close the window
void
processInput(GLFWwindow * window)
{
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

int
main()
{
    // Initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow * window = glfwCreateWindow(800, 600, "2D_RPG", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return 1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // set OpenGL options
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


      TextRenderer tr = TextRenderer();

    RendererMap rm(20, 80);
    rm.add_texture("./resources/sprites/test/grass/grass0.jpg", 0);
    rm.add_texture("./resources/sprites/test/grass/grass1.jpg", 1);
    rm.add_texture("./resources/sprites/test/grass/stone0.jpg", 2);
    // rm.add_texture("./resources/sprites/test/test3.jpg", 3);

    std::vector<int> map(20 * 80);
    for(int i = 0; i < 20 * 80; i++){
      map[i] = rand() % static_cast<int>(2 + 1);
    }
    rm.load_map(map);


    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // render code
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        rm.render();

        // check all events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        rm.set_camera(pos_x, pos_y);

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    glfwTerminate();

    return 0;
} // main

void
framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
    glViewport(0, 0, width, height);
    glfwMakeContextCurrent(window);
}
