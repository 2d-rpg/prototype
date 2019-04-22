#include "renderer_map.h"
#include <cassert>
#include "utils.h"

RendererMap::RendererMap(int width, int height) : width(width), height(height), tm(vertex_shader_file,
      fragment_shader_file)
{
    pos = std::vector<int>(2);

    // set VAO/VBO
    GLuint VBO;
    GLfloat vertices[] = {
        // position // texture
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

RendererMap::~RendererMap()
{
    delete(&tm);
    glDeleteVertexArrays(1, &this->VAO);
}

void
RendererMap::load_map(std::vector<int> &data)
{
    assert(data.size() == (long unsigned int) width * height);
    map = data;
}

int
RendererMap::get_tile(int x, int y)
{
    assert(x <= width && y <= height);
    return map[get_address_2D(width, height, x, y)];
}

void
RendererMap::set_camera(int x, int y)
{
    pos[0] = x;
    pos[1] = y;
}

void
RendererMap::render()
{
    // camera's position relative to grid 1
    int dx = pos[0] % tile_size;
    int dy = pos[1] % tile_size;

    // drawing coordinates
    int draw_x = (pos[0] - dx) / tile_size - screen_width / 2 / tile_size;
    int draw_y = (pos[1] - dy) / tile_size - screen_height / 2 / tile_size;

    for (int x = -dx; x <= screen_width; x += tile_size) {
        for (int y = -dy; y <= screen_height; y += tile_size) {
            draw_tile(std::to_string(get_tile(draw_x, draw_y)), glm::vec2(x, y),
              glm::vec2(tile_size, tile_size), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
            draw_y++;
        }
        draw_x++;
    }
}

void
RendererMap::draw_tile(std::string key, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color)
{
    tm.get_shader().use();
    glm::mat4 transform(1);

    // position
    transform = glm::translate(transform, glm::vec3(position, 0.0f));

    // rotation (from center)
    transform = glm::translate(transform, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    transform = glm::rotate(transform, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    transform = glm::translate(transform, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    // scale
    transform = glm::scale(transform, glm::vec3(size, 1.0f));

    // send transformation matrix
    glUniformMatrix4fv(glGetUniformLocation(tm.get_shader().ID, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

    // send color
    glUniform3f(glGetUniformLocation(tm.get_shader().ID, "sprite_color"), color.x, color.y, color.z);

    // render
    glActiveTexture(GL_TEXTURE0);
    tm.get_texture(key).bind();

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void
RendererMap::add_texture(const char * file_path, int key)
{
    tm.load(file_path, std::to_string(key));
}
