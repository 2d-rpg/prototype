#version 410 core

layout (location = 0) in vec4 vertex; // vec2 position; vec2 texture_coordinates

out vec2 texture_coordinates;

uniform mat4 transform;
uniform mat4 projection;

void main(){
  texture_coordinates = vertex.zw;
  gl_Position = projection * transform * vec4(vertex.xy, 0.0, 1.0);
}
