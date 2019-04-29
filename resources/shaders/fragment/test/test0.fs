#version 330 core
// output
out vec4 color;

// input from vertex shader
in vec3 out_color;
in vec2 out_tex_coord;

uniform sampler2D our_texture;

void main(){
  color = texture(our_texture, out_tex_coord) * vec4(out_color, 1.0);
}
