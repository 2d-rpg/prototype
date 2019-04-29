#version 410 core

in vec2 texture_coordinates;

out vec4 color;

uniform sampler2D texture_data;
uniform vec3 sprite_color;

void main(){
  color = vec4(sprite_color, 1.0) * texture(texture_data, texture_coordinates);
}
