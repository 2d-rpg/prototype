#include <renderer/renderer.h>
#include <utils.h>

Renderer::Renderer(int width, int height) : tm(vertex_shader_file, fragment_shader_file), screen_width(width), screen_height(height) {
  // set VAO and VBO
  GLuint VBO;
  GLfloat vertices[] = {
    // position,  texture
    0.0f, 1.0f,   0.0f, 1.0f,
    1.0f, 0.0f,   1.0f, 0.0f,
    0.0f, 0.0f,   0.0f, 0.0f,

    0.0f, 1.0f,   0.0f, 1.0f,
    1.0f, 1.0f,   1.0f, 1.0f,
    1.0f, 0.0f,   1.0f, 0.0f
  };
  // generate VAO and VBO
  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &VBO);

  //  initialize VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // generate VAO
  glBindVertexArray(this->VAO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *) 0);


  // unbind VAO and VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  tm.shader.use();
  glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(screen_width), static_cast<GLfloat>(screen_height), 0.0f, -1.0f, 1.0f);
  glUniformMatrix4fv(glGetUniformLocation(tm.shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}

void Renderer::render_square(std::string key, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color){
  tm.shader.use();
  glm::mat4 transform(1);

  // position
  transform = glm::translate(transform, glm::vec3(position, 0.0f));

  // rotation (from center)
  transform = glm::translate(transform, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
  transform = glm::rotate(transform, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
  transform = glm::translate(transform, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

  // scale
  transform = glm::scale(transform, glm::vec3(size, 1.0f));

  // send transformation matrix
  glUniformMatrix4fv(glGetUniformLocation(tm.shader.ID, "transform"), 1, GL_FALSE, glm::value_ptr(transform));

  // send color
  glUniform3f(glGetUniformLocation(tm.shader.ID, "sprite_color"), color.x, color.y, color.z);

  // render
  glActiveTexture(GL_TEXTURE0);
  tm.get_texture(key)->bind();
  glBindVertexArray(this->VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
}

void
Renderer::add_texture(const char * file_path, int key)
{
    tm.load(file_path, std::to_string(key));
}
