#version 330 core

layout(location = 0) out vec4 FragColor;

in vec2 texCoord;
in vec4 color;
in vec3 normal;

uniform vec3 matDiffuse;
uniform sampler2D sTexture;

void main()
{

    FragColor = vec4(normal.x, normal.y, normal.z, 1.0);
    //FragColor = texture(sTexture, texCoord);

} 