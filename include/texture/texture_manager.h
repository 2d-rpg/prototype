#pragma once

#include <utils.h>
#include <texture/texture_2D.h>
#include <shader/shader.h>
#include <map>
#include <string>

class TextureManager {
public:
    // shader
    const Shader                           shader;

private:
    // a map that gets Texture2Ds from
    std::map<std::string, Texture2D> textures;

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
