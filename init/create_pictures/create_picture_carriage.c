#include <libgcorewar.h>
#include <unistd.h>

static void	set_channels(unsigned char*	picture, size_t	i, t_vector color)
{
	picture[i * 4] = (char)(255.0f * color.x);
	picture[i * 4 + 1] = (char)(255.0f * color.y);
	picture[i * 4 + 2] = (char)(255.0f * color.z);
	picture[i * 4 + 3] = (char)(255.0f * color.w);
}

size_t math_length(void)
{
	const size_t	frame_length = (size_t)(0.3 * g_carriage_height);

	g_carriage_height += (frame_length * 2);
	g_carriage_width += (frame_length * 2);
	return (frame_length);
}

static	unsigned char* create_picture_array(size_t width, size_t height, t_vector color, const size_t frame_length)
{
	unsigned char*	picture;
	size_t	i;

	if (!(picture = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
		exit_error("create_picture malloc error");
	i = 0;
	while (i < width * height)
	{
		if ((i / width < frame_length
			 && (i % width < frame_length - i / width
				 || i % width >= width - (frame_length - i / width)))
			|| (i / width >= height - frame_length
				&& (i % width < (i / width - height + frame_length)
					|| i % width >= width - (i / width - height + frame_length))))
			set_channels(picture, i, color);
		else if (i / width >= frame_length && i % width >= frame_length
				 && i/ width < height - frame_length && i % width < width - frame_length)
			set_channels(picture, i, vec4(0.0f, 0.0f, 0.0f, 0.0f));
		else
			set_channels(picture, i, vec4(0.0, 0.3, 0.1, 1.0));
		i++;
	}
	return (picture);
}

GLuint	create_picture_carriege(t_vector color, size_t width, size_t height, const size_t frame_length)
{
	unsigned char* picture;
	GLuint	texture;
	float border_color[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	picture = create_picture_array(width, height, color, frame_length);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, picture);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(picture);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (texture);
}
