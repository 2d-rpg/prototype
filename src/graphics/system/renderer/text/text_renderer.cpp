#include "text_renderer.h"
#include <cstring>

TextRenderer::TextRenderer() : tm(vertex_shader_file, fragment_shader_file)
{
    for (int c = (int)'あ'; c < (int)'ん'; c++) {
      std::string s1(char_tex_dir + "/" + std::to_string(c) + ".png");
      char cs1[s1.size() + 1];
      strcpy(cs1, s1.c_str());
      tm.load(cs1, std::to_string(c));
      std::cout << cs1 << std::endl;
    }
};
