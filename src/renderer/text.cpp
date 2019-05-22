#include <renderer/text.h>
#include <texture/texture_manager.h>
#include <string>
#include <utils.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

TextRenderer::TextRenderer() : tm(vertex_shader_file, fragment_shader_file)
{
    // manually load all letters
    tm.load("../resources/fonts/hiragana/0.png", "0");
    tm.load("../resources/fonts/hiragana/1.png", "1");
    tm.load("../resources/fonts/hiragana/2.png", "2");
    tm.load("../resources/fonts/hiragana/3.png", "3");
    tm.load("../resources/fonts/hiragana/4.png", "4");
    tm.load("../resources/fonts/hiragana/5.png", "5");
    tm.load("../resources/fonts/hiragana/6.png", "6");
    tm.load("../resources/fonts/hiragana/7.png", "7");
    tm.load("../resources/fonts/hiragana/8.png", "8");
    tm.load("../resources/fonts/hiragana/9.png", "9");

    tm.load("../resources/fonts/hiragana/あ.png", "あ");
    tm.load("../resources/fonts/hiragana/い.png", "い");
    tm.load("../resources/fonts/hiragana/う.png", "う");
    tm.load("../resources/fonts/hiragana/え.png", "え");
    tm.load("../resources/fonts/hiragana/お.png", "お");
    tm.load("../resources/fonts/hiragana/か.png", "か");
    tm.load("../resources/fonts/hiragana/が.png", "が");
    tm.load("../resources/fonts/hiragana/き.png", "き");
    tm.load("../resources/fonts/hiragana/ぎ.png", "ぎ");
    tm.load("../resources/fonts/hiragana/く.png", "く");
    tm.load("../resources/fonts/hiragana/ぐ.png", "ぐ");
    tm.load("../resources/fonts/hiragana/け.png", "け");
    tm.load("../resources/fonts/hiragana/げ.png", "げ");
    tm.load("../resources/fonts/hiragana/こ.png", "こ");
    tm.load("../resources/fonts/hiragana/ご.png", "ご");
    tm.load("../resources/fonts/hiragana/さ.png", "さ");
    tm.load("../resources/fonts/hiragana/ざ.png", "ざ");
    tm.load("../resources/fonts/hiragana/し.png", "し");
    tm.load("../resources/fonts/hiragana/じ.png", "じ");
    tm.load("../resources/fonts/hiragana/す.png", "す");
    tm.load("../resources/fonts/hiragana/ず.png", "ず");
    tm.load("../resources/fonts/hiragana/せ.png", "せ");
    tm.load("../resources/fonts/hiragana/ぜ.png", "ぜ");
    tm.load("../resources/fonts/hiragana/そ.png", "そ");
    tm.load("../resources/fonts/hiragana/ぞ.png", "ぞ");
    tm.load("../resources/fonts/hiragana/た.png", "た");
    tm.load("../resources/fonts/hiragana/だ.png", "だ");
    tm.load("../resources/fonts/hiragana/ち.png", "ち");
    tm.load("../resources/fonts/hiragana/ぢ.png", "ぢ");
    tm.load("../resources/fonts/hiragana/つ.png", "つ");
    tm.load("../resources/fonts/hiragana/づ.png", "づ");
    tm.load("../resources/fonts/hiragana/て.png", "て");
    tm.load("../resources/fonts/hiragana/で.png", "で");
    tm.load("../resources/fonts/hiragana/と.png", "と");
    tm.load("../resources/fonts/hiragana/ど.png", "ど");
    tm.load("../resources/fonts/hiragana/な.png", "な");
    tm.load("../resources/fonts/hiragana/に.png", "に");
    tm.load("../resources/fonts/hiragana/ぬ.png", "ぬ");
    tm.load("../resources/fonts/hiragana/ね.png", "ね");
    tm.load("../resources/fonts/hiragana/の.png", "の");
    tm.load("../resources/fonts/hiragana/は.png", "は");
    tm.load("../resources/fonts/hiragana/ぱ.png", "ぱ");
    tm.load("../resources/fonts/hiragana/ば.png", "ば");
    tm.load("../resources/fonts/hiragana/ひ.png", "ひ");
    tm.load("../resources/fonts/hiragana/ぴ.png", "ぴ");
    tm.load("../resources/fonts/hiragana/び.png", "び");
    tm.load("../resources/fonts/hiragana/ふ.png", "ふ");
    tm.load("../resources/fonts/hiragana/ぷ.png", "ぷ");
    tm.load("../resources/fonts/hiragana/ぶ.png", "ぶ");
    tm.load("../resources/fonts/hiragana/へ.png", "へ");
    tm.load("../resources/fonts/hiragana/ぺ.png", "ぺ");
    tm.load("../resources/fonts/hiragana/べ.png", "べ");
    tm.load("../resources/fonts/hiragana/ほ.png", "ほ");
    tm.load("../resources/fonts/hiragana/ぽ.png", "ぽ");
    tm.load("../resources/fonts/hiragana/ぼ.png", "ぼ");
    tm.load("../resources/fonts/hiragana/ま.png", "ま");
    tm.load("../resources/fonts/hiragana/み.png", "み");
    tm.load("../resources/fonts/hiragana/む.png", "む");
    tm.load("../resources/fonts/hiragana/め.png", "め");
    tm.load("../resources/fonts/hiragana/も.png", "も");
    tm.load("../resources/fonts/hiragana/や.png", "や");
    tm.load("../resources/fonts/hiragana/ゆ.png", "ゆ");
    tm.load("../resources/fonts/hiragana/よ.png", "よ");
    tm.load("../resources/fonts/hiragana/ら.png", "ら");
    tm.load("../resources/fonts/hiragana/り.png", "り");
    tm.load("../resources/fonts/hiragana/る.png", "る");
    tm.load("../resources/fonts/hiragana/れ.png", "れ");
    tm.load("../resources/fonts/hiragana/ろ.png", "ろ");
    tm.load("../resources/fonts/hiragana/わ.png", "わ");
    tm.load("../resources/fonts/hiragana/ゐ.png", "ゐ");
    tm.load("../resources/fonts/hiragana/ゑ.png", "ゑ");
    tm.load("../resources/fonts/hiragana/を.png", "を");
    tm.load("../resources/fonts/hiragana/ん.png", "ん");

    tm.load("../resources/fonts/hiragana/ー.png", "ー");
    tm.load("../resources/fonts/hiragana/。.png", "。");
    tm.load("../resources/fonts/hiragana/、.png", "、");
    tm.load("../resources/fonts/hiragana/_.png", "　");

    // set up VBO/VAO
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // set projection uniform
    tm.get_shader().use();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), 0.0f, static_cast<GLfloat>(600));
    glUniformMatrix4fv(glGetUniformLocation(tm.get_shader().ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}

void
TextRenderer::render(std::u32string text, glm::vec3 color, glm::vec2 position, float size)
{
  tm.get_shader().use();
  glUniform3f(glGetUniformLocation(tm.get_shader().ID, "font_color"), color.x, color.y, color.z);
  glActiveTexture(GL_TEXTURE0);
  glBindVertexArray(VAO);

  for(char32_t c : text){
    GLfloat x_pos = position.x;
    GLfloat y_pos = position.y;

    GLfloat w = FONT_SIZE * size;
    GLfloat h = FONT_SIZE * size;

    // update VBO
    GLfloat vertices[6][4] = {
      {x_pos,     y_pos + h,  0.0f, 0.0f},
      {x_pos,     y_pos,      0.0f, 1.0f},
      {x_pos + w, y_pos,      1.0f, 1.0f},

      {x_pos,     y_pos + h,  0.0f, 0.0f},
      {x_pos + w, y_pos,      1.0f, 1.0f},
      {x_pos + w, y_pos + h,  1.0f, 0.0f}
    };

    tm.get_texture(converter.to_bytes(c))->bind();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    position.x += w;
  }
  glBindVertexArray(0);
  glBindTexture(GL_TEXTURE_2D, 0);
}
