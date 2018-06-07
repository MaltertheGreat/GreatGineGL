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
	float specular_strength = 0.8f;

	vec3 light = light_pos - vec3(Position);
	float power = 1.0f - clamp(dot(light, light) / 16.0f, 0.0f, 1.0f);
	light = normalize(light);

	vec3 norm = vec3(texture(texture1, TexCoords));
	norm = 2.0f * norm;
	norm = norm - vec3(1.0f, 1.0f, 1.0f);
	norm = TBN * norm;

	float diffuse = dot(norm, light);

	vec3 view = normalize(camera_pos - Position);
	vec3 reflection = reflect(-light, norm);
	float specular = pow(max(dot(view, reflection), 0.0), 128);
	specular = specular_strength * specular;
	specular = min(2.0f, specular);

	color = color * diffuse + specular;
	color = color * power;
	FragColor = vec4(color, 1.0f);
}
