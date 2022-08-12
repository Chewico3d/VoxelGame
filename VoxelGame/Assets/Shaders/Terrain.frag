#version 460 core

out vec4 FragColor;
layout(location = 0) uniform sampler2D screen;
in vec2 UVs;

void main()
{
	FragColor = texture(screen, UVs);
}