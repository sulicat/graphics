#version 320 es
layout (location = 0) in vec3 aPos;

out vec4 vertColor;

void main(){
  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
  vertColor = vec4(aPos, 1.0);
}

