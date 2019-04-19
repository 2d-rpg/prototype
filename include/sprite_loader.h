#ifndef _SPRITE_LOADER_H
#define _SPRITE_LOADER_H


#include "texture_2D.h"
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Sprite_Loader {
public:
  // constructor
  Sprite_Loader(Shader &shader);
  ~Sprite_Loader();

  // renders a qual textured with given sprite
  void draw(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));

private:
  // render state
  Shader shader;
  GLuint VAO;

  // initialize and configure the quad's buffer and vertex attributes
  void init();
};

#endif
