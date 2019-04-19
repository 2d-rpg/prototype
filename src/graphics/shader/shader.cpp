#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "utils.h"
#include "shader.h"
#include <string>
#include <iostream>


Shader::Shader(const char *v_file_path, const char *f_file_path){
  if(!load_shaders(v_file_path, f_file_path, ID)){
    std::cerr << "Failed to construct the shader program." << std::endl;
  }
}

void Shader::use()
{
  glUseProgram(ID);
}

template <typename T>
void Shader::set(const std::string &name, T value) const{
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

// Compile shader program
bool Shader::compile_shader(const char *vsource, const char *fsource, unsigned int &ret_shader_program){
  unsigned int vertex_shader {glCreateShader(GL_VERTEX_SHADER)};
  unsigned int fragment_shader {glCreateShader(GL_FRAGMENT_SHADER)};
  int success; char info[512];

  // vertex shader
  glShaderSource(vertex_shader, 1, &vsource, NULL);
  glCompileShader(vertex_shader);
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(vertex_shader, 512, NULL, info);
    std::cerr << "Failed to compile vertex shader.\n" << info << std::endl;
    return false;
  }

  // fragment shader
  glShaderSource(fragment_shader, 1, &fsource, NULL);
  glCompileShader(fragment_shader);
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(fragment_shader, 512, NULL, info);
    std::cerr << "Failed to compile fragment shader.\n" << info << std::endl;
    return false;
  }

  // link shaders
  unsigned int shader_program {glCreateProgram()};
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);
  glLinkProgram(shader_program);
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
  if(!success){
    glGetProgramInfoLog(shader_program, 512, NULL, info);
    std::cerr << "Failed to link shader programs.\n" << info << std::endl;
    return false;
  }
  glDeleteShader(vertex_shader); glDeleteShader(fragment_shader);

  ret_shader_program = shader_program;
  return true;
}

// load shader programs from file
bool Shader::load_shaders(const char* vfile, const char* ffile, unsigned int &shader_program){
  std::vector<char> vsource, fsource;
  if(!(readfile(vfile, vsource) && readfile(ffile, fsource))){
    return false;
  }
  if(!compile_shader(vsource.data(), fsource.data(), shader_program)){
    return false;
  }
  return true;
}
