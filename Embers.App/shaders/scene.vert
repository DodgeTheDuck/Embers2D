#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec2 texCoord;
out vec4 color;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); 
    texCoord = aTexCoord;
    color = aColor;
}  