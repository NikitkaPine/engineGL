#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;
in vec3 Normal;
in vec3 crntPos;

uniform sampler2D tex0; // Дифузная текстура
uniform sampler2D tex1; // Спекулярная текстура
uniform vec4 lightColor; // Цвет света
uniform vec3 lightPos; // Позиция источника света
uniform vec3 camPos; // Позиция камеры

void main()
{
    float ambient = 0.40f; // Значение амбиентного освещения

    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - crntPos);

    // Расчет диффузного освещения
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    // Расчет спекулярного освещения
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
    float specular = specAmount * specularLight;

    // Установка цвета фрагмента
    FragColor = (texture(tex0, texCoord) * (diffuse + ambient) + texture(tex1, texCoord).r * specular) * lightColor;

}
