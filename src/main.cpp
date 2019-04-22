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

    Shader shader("./resources/shaders/vertex/test1.vs", "./resources/shaders/fragment/test1.fs");

    Texture2D texture;
    texture.generate("./resources/sprites/test/test0.jpg");

    Sprite_Loader sprite_loader(shader);

    shader.use();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), static_cast<GLfloat>(600), 0.0f, -1.0f, 1.0f);
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // render code
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        sprite_loader.draw(texture, glm::vec2(0, 0), glm::vec2(100, 100), 1.57f, glm::vec3(0.0f, 0.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(100, 0), glm::vec2(100, 100), 1.57f, glm::vec3(0.0f, 1.0f, 0.0f));
        sprite_loader.draw(texture, glm::vec2(0, 100), glm::vec2(100, 100), 1.57f, glm::vec3(1.0f, 0.0f, 0.0f));
        sprite_loader.draw(texture, glm::vec2(100, 100), glm::vec2(300, 300), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(200, 0), glm::vec2(200, 100), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        sprite_loader.draw(texture, glm::vec2(0, 200), glm::vec2(100, 200), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

        // check all events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
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
