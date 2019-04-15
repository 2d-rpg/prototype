#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

// Read a text file and put its content in a buffer
bool readfile(const char *name, std::vector<char> &buffer){
  std::ifstream fs {name};
  if(!fs){
    std::cerr << "Failed to open file: '" << name << "'" << std::endl;
    return false;
  }

  // Get file size
  fs.seekg(0L, std::ios::end);
  int size = fs.tellg();

  // Resize the buffer to the appropriate size
  buffer.resize(size + 1);

  // Read the file from the beggining
  fs.seekg(0L, std::ios::beg);
  fs.read(buffer.data(), size);
  buffer[size] = '\0';

  if(!fs){
    std::cerr << "Failed while reading file: '" << name << "'" << std::endl;
    return false;
  }

  fs.close();
  return true;
}

// Compile shader program
bool compile_shader(const char *vsource, const char *fsource, unsigned int &ret_shader_program){
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

bool load_shaders(const char* vfile, const char* ffile, unsigned int &shader_program){
  std::vector<char> vsource, fsource;
  if(!(readfile(vfile, vsource) && readfile(ffile, fsource))){
    return false;
  }
  if(!compile_shader(vsource.data(), fsource.data(), shader_program)){
    return false;
  }
  return true;
}


// // for testing shader compiler
// int main(){
//   glfwInit();
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//   glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//   GLFWwindow* window = glfwCreateWindow(800, 600, "2D_RPG", NULL, NULL);
// 	if (window == NULL) {
// 		std::cout << "Failed to create GLFW window." << std::endl;
// 		glfwTerminate();
// 		return 1;
// 	}
//   glfwMakeContextCurrent(window);
//   // Initialize GLAD
// 	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
// 		std::cout << "Failed to initialize GLAD." << std::endl;
// 		return 1;
// 	}
// 	glViewport(0, 0, 800, 600);
//
//   std::vector<char> buffer;
//   if(readfile("../resources/test/dummy.txt", buffer)){
//     std::cout << buffer.data() << std::endl;
//     compile_shader(buffer.data(), buffer.data());
//   }
//   return 0;
// }
