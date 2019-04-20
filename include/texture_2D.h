#ifndef _TEXTURE_2D_H
#define _TEXTURE_2D_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// load a texture from file to use in OpenGL
class Texture2D {
public:
    // texture ID
    GLuint ID;

    // 2D texture dimensions
    GLuint width, height;

    // texture format
    GLuint internal_format;
    GLuint format;

    // texture configuration
    GLuint wrap_s, wrap_t;         // wrapping mode on S and T axis
    GLuint filter_mag, filter_min; // filtering modes when magnifiing and minimizing

    // Constructor
    // load texture with default settings
    Texture2D();
    ~Texture2D();

    // generate textures
    void
    generate(const char * file_path);

    // bind texture for use
    void
    bind() const;
};

#endif // ifndef _TEXTURE_2D_H
