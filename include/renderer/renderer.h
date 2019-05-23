#pragma once

#include <texture/texture_manager.h>
#include <vector>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// general purpose renderer
class Renderer {
private:
  // shaders
  const GLchar * vertex_shader_file {"../resources/shaders/vertex/renderer.vs"};
  const GLchar * fragment_shader_file {"../resources/shaders/fragment/renderer.fs"};

  // texture manager
  TextureManager tm;

  // VAO
  GLuint VAO;

public:
  // parameters for rendering
  const int screen_width, screen_height;

  // constructor and destructor
  Renderer(int width, int  height);

  // render
  void render_square(std::string key, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color);

  // add texture
  void add_texture(const char * file_path, int key);
};
