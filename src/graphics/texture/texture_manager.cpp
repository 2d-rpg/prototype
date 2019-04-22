#include "texture_manager.h"
#include "shader.h"

TextureManager::TextureManager(const GLchar * vertex_shader,
  const GLchar *                              fragment_shader) : shader(vertex_shader, fragment_shader)
{ }

TextureManager::~TextureManager(){
  for(auto const& [key, texture] : textures){
    delete(&texture);
  }
}

void
TextureManager::load(const char * file_path, std::string name)
{
    textures[name] = Texture2D();
    textures[name].generate(file_path);
};

Shader
TextureManager::get_shader()
{
    return this->shader;
}

Texture2D
TextureManager::get_texture(std::string key)
{
    std::map<std::string, Texture2D>::iterator ret = this->textures.find(key);

    if (ret == this->textures.end()) {
        std::cerr << "could not find texture with that key. (TextureManager)" << std::endl;
    }
    return ret->second;
}
