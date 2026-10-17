#version 330 core
out vec4 FragColor;

in vec3 crntPos;
in vec3 Normal;
in vec2 texCoord;


uniform sampler2D tex;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

vec4 pointLight()
{
	vec3 lightVec = lightPos - crntPos;
	float dist = length(lightVec);
	float a = 3.0;
	float b = 0.7;
	float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);

	float ambient = 0.20f;

	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightVec);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	return (texture(tex, texCoord) * (diffuse * inten + ambient)) * lightColor;
}

vec4 direcLight()
{
	float ambient = 0.50f;

	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(vec3(0.75f, 1.0f, 0.5f));
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	return (texture(tex, texCoord) * (diffuse + ambient)) * lightColor;
}

vec4 spotLight()
{
	float outerCone = 0.90f;
	float innerCone = 0.95f;

	float ambient = 0.20f;

	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - crntPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirection);
	float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);

	return (texture(tex, texCoord) * (diffuse * inten + ambient)) * lightColor;
}

void main()
{
	FragColor = direcLight();
}