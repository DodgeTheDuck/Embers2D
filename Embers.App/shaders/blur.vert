#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 uMvp;
uniform vec2 uDirection;

noperspective out vec2 screenSpaceCoord;
out vec2 texCoord;
out vec4 color;
out vec2 direction;

void main()
{
    gl_Position = uMvp * vec4(aPos, 1.0);
	texCoord = aTexCoord;
    color = aColor;
    screenSpaceCoord = (gl_Position.xy / gl_Position.w) * (0.5) + vec2(0.5);
    direction = uDirection;
}