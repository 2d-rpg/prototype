#include "texture_manager.h"
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RendererMap {
private:
    // shaders
    const GLchar * vertex_shader_file { "../resources/shaders/vertex/renderer_map.vs" };
    const GLchar * fragment_shader_file { "../resources/shaders/fragment/renderer_map.fs" };

    // rendering parameters
    const int tile_size {100};
    const int screen_width {800};
    const int screen_height {600};

    // map data
    int width, height;
    std::vector<int> map;

    // texture manager for this renderer
    TextureManager tm;

    // posistion on the map
    std::vector<int> pos;

    // draw texture
    void
    draw_tile(std::string key, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color);

    GLuint VAO;

public:
    // constructor/destructor
    RendererMap(int width, int height);
    ~RendererMap();

    // load map data
    void
    load_map(std::vector<int> &data);

    // add texture with key
    void
    add_texture(const char * file_path, int key);

    // get tile number at
    int
    get_tile(int x, int y);

    // set camera on map
    void
    set_camera(int x, int y);

    // render
    void
    render();
};
