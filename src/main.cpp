/*
 * Copyright 2019 2d-rpg Project Team - All Rights Reserved.
 * Written by Jumpei Yoshikawa, Shinji Hoshino and Yasuaki Yoshii
 */

#include <iostream>
extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}
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
    // Initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "2D_RPG", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return 1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
#ifndef __MINGW32__  // except MinGW32
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
#endif
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
}
