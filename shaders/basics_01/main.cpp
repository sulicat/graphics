#define GL_GLEXT_PROTOTYPES

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <sstream>

/* ******************************************************************************** */
int window_size_x = 1280;
int window_size_y = 720;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

unsigned int VBO; // vertext buffer object
unsigned int vertexShader;
unsigned int fragmentShader;
unsigned int shaderProgram;

std::string load_shader( std::string path ){
  std::ifstream inFile;
  inFile.open(path);

  std::stringstream strStream;
  strStream << inFile.rdbuf(); //read the file
  std::string str = strStream.str(); //str holds the content of the file

  return str;
}


std::string temp = load_shader( "vertex_shader.glsl" );
const char* v_shader = temp.c_str();
int v_shader_len = temp.length();

std::string temp2 = load_shader( "frag_shader.glsl" );
const char* f_shader = temp2.c_str();
int f_shader_len = temp2.length();


/* ******************************************************************************** */
void render( int ){
}

void disp( void ){
  glViewport( 0, 0, window_size_x, window_size_y);
  glClearColor( 1.0, 1.0, 1.0, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT );

  glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );

  glDrawArrays( GL_TRIANGLES, 0, 3 );

  glutSwapBuffers();
  glutTimerFunc( 10, render, 0 );
}


/* ******************************************************************************** */
int main( int argc, char** argv ){
  glutInit( &argc, argv );
  glutInitWindowSize( window_size_x, window_size_y );
  glutInitWindowPosition( 0, 0 );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );

  glutCreateWindow( "Ray" );
  glutDisplayFunc( disp );

  // VBO is the vertex buffer object that controls that buffer we will define
  glGenBuffers( 1, &VBO ); // generate a buffer on the graphics card
  glBindBuffer( GL_ARRAY_BUFFER, VBO );  // bind that buffer to the vertext shader

  vertexShader = glCreateShader( GL_VERTEX_SHADER );
  glShaderSource( vertexShader, 1, &v_shader, &v_shader_len);
  glCompileShader( vertexShader );

  fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
  glShaderSource( fragmentShader, 1, &f_shader, &f_shader_len );
  glCompileShader( fragmentShader );

  int  success;
  char infoLog[512];

  // check vertex shader compilation
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  std::cout << "vertex status = " << success << "\n";
  if(!success){
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }


  // check fragment shader compilation
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  std::cout << "fragment status = " << success << "\n";
  if(!success){
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::Fragment::COMPILATION_FAILED\n" << infoLog << std::endl;
  }


  shaderProgram = glCreateProgram();
  glAttachShader( shaderProgram, vertexShader );
  glAttachShader( shaderProgram, fragmentShader );
  glLinkProgram( shaderProgram );

  // check shader status
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  std::cout << "Shader status = " << success << "\n";
  if(!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
  }


  // inform opengl of our vertex structure
  // float       ...
  // v1    v2    ...
  // x y z x y z ...

  glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0 );
  glEnableVertexAttribArray(0);


  // use the new shaders
  glUseProgram( shaderProgram );


  glutMainLoop();


  return 0;
}
