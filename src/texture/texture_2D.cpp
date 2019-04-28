#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "texture_2D.h"
#include "utils.h"

// load texture with default settings
Texture2D::Texture2D()
    : width(0), height(0), internal_format(GL_RGB), format(GL_RGB),
    wrap_s(GL_REPEAT), wrap_t(GL_REPEAT), filter_mag(GL_LINEAR), filter_min(GL_LINEAR){ }

// unload texture
Texture2D::~Texture2D()
{
    glDeleteTextures(1, &(this->ID));
}

void
Texture2D::generate(const char * file_path)
{
    // load texture from file
    int width, height;
    unsigned char * img_data = stbi_load(file_path, &width, &height, NULL, 0);

    this->width  = width;
    this->height = height;

    // generate texture for OpenGL
    glGenTextures(1, &(this->ID));
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format, this->width, this->height, 0, this->format, GL_UNSIGNED_BYTE,
      img_data);

    // set texture configuration
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_mag);

    // generate mipmaps
    glGenerateMipmap(GL_TEXTURE_2D);

    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

    // unload image data from memory
    stbi_image_free(img_data);
}

void
Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
