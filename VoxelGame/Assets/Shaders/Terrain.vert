#version 460 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 uvs;

out vec2 UVs;
uniform mat4 matrix;

void main()
{
	gl_Position = matrix * vec4(pos.x, pos.y, -pos.z, 1.0);
	UVs = uvs;
}