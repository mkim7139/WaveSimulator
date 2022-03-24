#version 330 core
#define PI 3.1415926538

layout(location = 0) in vec4 Pos;


out vec4 position;



void main()
{
    position = Pos;
    gl_Position = Pos;
}
