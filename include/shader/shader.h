#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "utils.h"

class Shader {
public:
    // the program id
    unsigned int ID;

    // the constructor will compile the shader from the given source files.
    Shader(const GLchar* v_file_path, const GLchar* f_file_path);

    // use the shader
    void use();

    // uniform functions
    template <typename T>
    void set(const std::string& name, T value) const;

private:
    // compile shaders
    bool compile_shader(const char* vsrouce, const char* fsource, unsigned int& id);

    // load shader programs from file
    bool load_shaders(const char* vfile, const char* ffile, unsigned int& id);
};
