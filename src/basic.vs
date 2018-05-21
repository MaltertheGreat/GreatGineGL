#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 viewProj;

out vec4 Position;
out vec4 Normal;

void main()
{
	Position = model * vec4(aPos, 1.0f);
	Normal = model * vec4(aNormal, 1.0f);
	gl_Position = viewProj * Position;
	Position = gl_Position;
}
