#shader vertex
#version 460 core

layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 Tex;

out vec2 Coords;


layout (std140) uniform Camera
{
    mat4 proj;
};

uniform mat4 view;
uniform mat4 model;

void main()
{
	Coords = Tex;
	gl_Position = proj * view * model * vec4(Pos,1.0);
}



#shader fragment
#version 460 core

out vec4 FragColour;

in vec2 Coords;

uniform sampler2D surface;

void main()
{
	//FragColour = vec4(1.0,0.0,0.25,1.0);
	FragColour = texture(surface,Coords);
}