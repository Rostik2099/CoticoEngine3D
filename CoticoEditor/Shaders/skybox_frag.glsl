#version 330 core
out vec4 FragColor;

in vec3 texCoords;

uniform samplerCube skybox0;

void main()
{
	FragColor = texture(skybox0, texCoords);
}