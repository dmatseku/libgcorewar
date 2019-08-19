#version 410 core

layout (location = 0) in vec2   position;

layout (location = 1) in vec2   tex;

uniform mat4                    model;

out vec2                        texture_coords;

void main()
{
    gl_Position = model * vec4(position, 0.0f, 1.0f);
    texture_coords = tex;
}