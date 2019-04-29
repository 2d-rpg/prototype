#version 410

layout (location = 0) in vec4 vertex; // vec2 pos, vec2 texture_coordinates

out vec2 texture_coordinates;

uniform mat4 projection;

void main(){
  gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);
  texture_coordinates = vertex.zw;
}
