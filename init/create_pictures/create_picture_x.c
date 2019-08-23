#include <libgcorewar.h>
#include <unistd.h>

static void				draw_line_1(unsigned char* picture, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		picture[(i * width + i) * 4 + 3] = 255;
//		picture[i * 4 + 3] = 255;
//		picture[i * width * 4 + 3] = 255;
//		picture[(i + width * (width - 1)) * 4 + 3] = 255;
//		picture[(i * width + width - 1) * 4 + 3] = 255;
		if (i < width - 1)
		{
			picture[(i * width + i + 1) * 4 + 3] = 255;
			picture[((i + 1) * width + i) * 4 + 3] = 255;
			picture[(i * width + i + 2) * 4 + 3] = 255;
			picture[((i + 2) * width + i) * 4 + 3] = 255;
		}
		i++;
	}
}

static void				draw_line_2(unsigned char* picture, size_t width)
{
	size_t i;
	size_t j;

	i = width - 1;
	j = 0;
	while (j < width)
	{
		picture[(i * width + j) * 4 + 3] = 255;
		if (j < width - 1)
		{
			picture[(i * width + j + 1) * 4 + 3] = 255;
			picture[((i - 1) * width + j) * 4 + 3] = 255;
			picture[(i * width + j + 2) * 4 + 3] = 255;
			picture[((i - 2) * width + j) * 4 + 3] = 255;
		}
		i--;
		j++;
	}
}

static unsigned char*	create_picture_array(size_t width)
{
	unsigned char*	picture;

	if (!(picture = (unsigned char*)malloc(sizeof(unsigned char) * width * width * 4)))
		exit_error("create_picture malloc error");
	my_memset(picture, 0, sizeof(unsigned char) * width * width * 4);
	draw_line_1(picture, width);
	draw_line_2(picture, width);
//	size_t i;
//	i = 0;
//	while (i < width * width)
//	{
//		if (i && !(i % width))
//			write(1, "\n", 1);
//		if (picture[i * 4 + 3])
//			write(1, "*", 1);
//		else
//			write(1, " ", 1);
//		i++;
//	}
	return (picture);
}

GLuint	create_picture_x(size_t width)
{
	unsigned char* picture;
	GLuint	texture;
	float border_color[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	picture = create_picture_array(width);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, width, 0, GL_RGBA, GL_UNSIGNED_BYTE, picture);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(picture);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (texture);
}