#version 410 core

in vec2 texture_coordinates;

out vec4 color;

uniform sampler2D font_texture;
uniform vec3 font_color;

void main(){
  vec4 sampled = vec4(1.0, 1.0, 1.0, texture(font_texture, texture_coordinates).r);
  color = vec4(font_color, 1.0) * sampled;
}
