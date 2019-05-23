#pragma once

#include <texture/texture_manager.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <renderer/renderer.h>

class RendererMap {
private:
    // rendering parameters
    const int tile_size{50};
    Renderer &renderer;

    // map data
    int              width, height;
    std::vector<int> map;

    // posistion on the map
    std::vector<int> pos;

public:
    // constructor/destructor
    RendererMap(int width, int height, Renderer &renderer);
    ~RendererMap();

    // load map data
    void load_map(std::vector<int>& data);

    // get tile number at
    int get_tile(int x, int y);

    // set camera on map
    void set_camera(int x, int y);

    // render
    void render();
};
