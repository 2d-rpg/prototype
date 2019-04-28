#include <utils.h>
#include <texture/texture_2D.h>
#include <shader/shader.h>
#include <map>
#include <string>

class TextureManager {
private:
    std::map<std::string, Texture2D> textures;
    Shader                           shader;

public:
    // constructor
    TextureManager(const GLchar* vertex_shader, const GLchar* fragment_shader);
    ~TextureManager();

    // load a new texture
    void load(const char* file_path, std::string name);

    // get the shader
    Shader get_shader();

    // get a texture from string
    Texture2D * get_texture(std::string key);
};
