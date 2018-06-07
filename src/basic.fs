#version 330 core

uniform sampler2D texture1;
uniform sampler2D normal_map;
uniform vec3 light_pos;
uniform vec3 camera_pos;

in vec3 Position;
in mat3 TBN;
in vec2 TexCoords;

out vec4 FragColor;

void main()
{
	vec3 color = vec3(texture(texture1, TexCoords));
	float specular_strength = 0.5f;

	vec3 light = light_pos - vec3(Position);
	float distance = length(light);
	float attenuation = 1.0 / (1.0f + 0.7f * distance + 1.8f * (distance * distance));
	light = normalize(light);

	vec3 norm = vec3(texture(normal_map, TexCoords));
	norm = 2.0f * norm;
	norm = norm - vec3(1.0f, 1.0f, 1.0f);
	norm.x = -norm.x;
	norm.y = -norm.y;
	norm = TBN * norm;

	float diffuse = dot(norm, light);
	diffuse *= attenuation;

	vec3 view = normalize(camera_pos - Position);
	vec3 reflection = reflect(-light, norm);
	float specular = pow(max(dot(view, reflection), 0.0), 32);
	specular = specular_strength * specular;
	specular *= attenuation;

	color = color * diffuse + specular;
	FragColor = vec4(color, 1.0f);
}
