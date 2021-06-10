#version 330 core

out vec4 FragColor;

in vec2 texCoord;
in vec4 color;

uniform vec3 matDiffuse;
uniform sampler2D sTexture;

void main()
{
    FragColor = color; // * texture(sTexture, texCoord);
} 