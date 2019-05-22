#version 330 core

in vec2 texture_coordinates;

out vec4 color;

uniform sampler2D texture_data;
uniform vec3 font_color;

void main(){
  vec4 sampled = vec4(1.0, 1.0, 1.0, texture(texture_data, texture_coordinates).w);
  color = vec4(font_color, 1.0) * sampled;
}
