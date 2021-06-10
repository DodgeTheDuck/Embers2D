#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 uMvp;

out vec2 texCoord;
out vec4 color;


void main()
{
    gl_Position = uMvp * vec4(aPos, 1.0);
	texCoord = aTexCoord;
    color = aColor;
}