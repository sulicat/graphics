#version 320 es
precision highp float;

in vec4 vertColor;

out vec4 FragColor;

void main(){
  //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
  FragColor = vertColor;
}

