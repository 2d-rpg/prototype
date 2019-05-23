#include <renderer/map.h>
#include <cassert>
#include <utils.h>

RendererMap::RendererMap(int width, int height, Renderer &renderer) : renderer(renderer), width(width), height(height) 
{
    pos = std::vector<int>(2);
    map = std::vector<int>(width * height);
}

RendererMap::~RendererMap()
{
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
    int draw_x = (pos[0] - dx) / tile_size - renderer.screen_width / 2 / tile_size;
    int draw_y = (pos[1] - dy) / tile_size - renderer.screen_height / 2 / tile_size;

    int init_draw_y = draw_y;

    for (int x = -dx; x <= renderer.screen_width; x += tile_size) {
        draw_y = init_draw_y;
        for (int y = -dy; y <= renderer.screen_height; y += tile_size) {
            if (draw_x >= 0 && draw_y >= 0 && draw_x < width && draw_y < height) {
                renderer.render_square(std::to_string(get_tile(draw_x, draw_y)), glm::vec2(x, y),
                  glm::vec2(tile_size, tile_size), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
            }
            draw_y++;
        }
        draw_x++;
    }
}
