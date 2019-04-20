#include "texture_manager.h"
#include <vector>
#include <glm/glm.hpp>

class RendererMap {
public:
    // constructor/destructor
    RendererMap(int width, int height, TextureManager tm);
    ~RendererMap();

    // get tile number at
    int
    get_tile(int x, int y);

    // set camera on map
    void
    set_camera(int x, int y);

private:
    // texture manager for this renderer
    TextureManager tm;

    // posistion on the map
    std::vector<int> pos;

    // map data
    int width, height;
};
