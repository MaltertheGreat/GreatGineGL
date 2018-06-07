#version 330 core

uniform sampler2D texture1;
uniform vec3 light_pos;
uniform vec3 camera_pos;

in vec3 Position;
in mat3 TBN;
in vec2 TexCoords;

out vec4 FragColor;

void main()
{
	vec3 color = vec3(1.0f, 0.5f, 0.2f);
	vec3 light_color = vec3(1.0f, 1.0f, 1.0f);
	float specular_strength = 0.3f;

	vec3 light = light_pos - vec3(Position);
	light = normalize(light);

	vec3 norm = vec3(texture(texture1, TexCoords));
	norm = 2.0f * norm;
	norm = norm - vec3(1.0f, 1.0f, 1.0f);
	norm = TBN * norm;

	color = color * dot(norm,  light);

	vec3 view = normalize(camera_pos - Position);
	vec3 reflection = reflect(-light, norm);

	float spec = pow(max(dot(view, reflection), 0.0), 128);
	vec3 specular = specular_strength * spec * light_color;

	color = color + specular;
	FragColor = vec4(color, 1.0f);
}
