#include "headers/sprite_loader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Sprite_Loader::Sprite_Loader(Shader &shader) : shader(shader){
  this->init();
}

Sprite_Loader::~Sprite_Loader(){
  glDeleteVertexArrays(1, &this->VAO);
}

void Sprite_Loader::draw(Texture2D &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color){
  // prepare transfomation
  this->shader.use();
  glm::mat4 trans(1);

  // position
  trans = glm::translate(trans, glm::vec3(position, 0.0f));

  // rotation (from center)
  trans = glm::translate(trans, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
  trans = glm::rotate(trans, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
  trans = glm::translate(trans, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

  // scale
  trans = glm::scale(trans, glm::vec3(size, 1.0f));

  // send transformation matrix
  glUniformMatrix4fv(glGetUniformLocation(this->shader.ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));

  // send color
  glUniform3f(glGetUniformLocation(this->shader.ID, "sprite_color"), color.x, color.y, color.z);

  // render
  glActiveTexture(GL_TEXTURE0);
  texture.bind();

  glBindVertexArray(this->VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);

  this->shader;
}

void Sprite_Loader::init(){
  // set VAO/VBO
  GLuint VBO;
  GLfloat vertices[] = {
    // position // texture
    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,

    0.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 0.0f
  };

  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(this->VAO);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*) 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
