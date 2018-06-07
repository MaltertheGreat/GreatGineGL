#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aTangent;
layout (location = 3) in vec2 aTexCoords;

uniform mat4 model_matrix;
uniform mat4 view_proj_matrix;
uniform mat3 normal_matrix;

out vec3 Position;
out mat3 TBN;
out vec2 TexCoords;

void main()
{
	vec3 normal = normalize(normal_matrix * aNormal);
	vec3 tangent = normalize(normal_matrix * aTangent);
	vec3 bitangent = cross(normal, tangent);

	TBN = mat3(tangent, bitangent, normal);
	TBN = transpose(TBN);

	vec4 pos = model_matrix * vec4(aPos, 1.0f);

	Position = vec3(pos);
	TexCoords = aTexCoords;
	gl_Position = view_proj_matrix * pos;
}
