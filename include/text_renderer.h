#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "texture_manager.h"

// this class is used to render text. only supports Japanese Hiragana
class TextRenderer {
private:
    // shader file sources
    const char * vertex_shader_file { "./resources/shaders/vertex/text_renderer.vs" };
    const char * fragment_shader_file { "./resources/shaders/fragment/text_renderer.fs" };

    // character textures directory
    const std::string char_tex_dir {"./resources/sprites/fonts/japanese/hiragana"};

    // texture manager
    TextureManager tm;

public:
    TextRenderer();
};
