#version 330 core

in vec4 Position;
in vec4 Normal;

out vec4 FragColor;

void main()
{
	vec4 lightDir = normalize(vec4(-1.0f, 1.0f, -0.5f, 1.0f));
	vec3 color = vec3(1.0f, 0.5f, 0.2f);

	color = color * max(dot(Normal, lightDir), 0.1f);
	FragColor = vec4(color, 1.0f);
}
