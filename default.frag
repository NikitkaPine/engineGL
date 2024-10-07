//Fragment shader
#version 330 core
out vec4 FragColor;

in vec3 color;

void main()
{
    // Yellow
    FragColor = vec4(color, 1.0f);
}
