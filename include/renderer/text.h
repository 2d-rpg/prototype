#pragma once

#include <string>
#include <texture/texture_manager.h>
#include <glm/glm.hpp>
#include <codecvt>
#include <locale>

// renders the given string at a given point and with a given size on the screen.
// as of 2019-5-21 only implemented for hiragana.
class TextRenderer {
private:
  // constant values
  const GLchar * fragment_shader_file {"../resources/shaders/fragment/text_renderer.fs"};
  const GLchar * vertex_shader_file {"../resources/shaders/vertex/text_renderer.vs"};
  const int FONT_SIZE {200};

  // rendering parameters
  const int screen_width {800};
  const int screen_height {600};

  // texture manager
  TextureManager tm;

  // VAO, VBO
  GLuint VAO, VBO;

  // character converter
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

public:
  // constructor / destructor
  TextRenderer();
  ~TextRenderer() = default;

  // render text
  void render(std::u32string text, glm::vec3 color, glm::vec2 position, float size);
};
