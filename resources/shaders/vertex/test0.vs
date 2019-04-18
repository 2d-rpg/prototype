#version 330 core
// the position variale has the attribute position 0
layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec3 in_color;
layout (location = 2) in vec2 in_tex_coord;

// output to  fragment shader
out vec3 out_color;
out vec2 out_tex_coord;

uniform mat4 transform;

void main(){
  gl_Position = transform * vec4(in_pos, 1.0f);
  out_color = in_color;
  out_tex_coord = in_tex_coord;
}
