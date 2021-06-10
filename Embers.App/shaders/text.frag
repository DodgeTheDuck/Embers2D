#version 330 core

out vec4 FragColor;

in vec2 texCoord;
in vec4 color;

uniform vec3 matDiffuse;
uniform sampler2D sTexture;
uniform sampler2D sLastPass;

void main()
{
    FragColor = vec4(1.0, 1.0, 1.0, texture(sTexture, texCoord).a); // * texture(sTexture, texCoord);
} 