#include <libgcorewar.h>

static void	set_channels(unsigned char*	picture, size_t	i, t_vector color)
{
	picture[i * 4] = (char)(255.0f * color.x);
	picture[i * 4 + 1] = (char)(255.0f * color.y);
	picture[i * 4 + 2] = (char)(255.0f * color.z);
	picture[i * 4 + 3] = (char)(255.0f * color.w);
}

unsigned char*	create_picture_carriege(t_vector color, size_t width, size_t height)
{
	unsigned char*	picture;
	size_t	i;
	const size_t	frame_length = (size_t)((float)height / 0.2f);
	if (!(picture = (unsigned char*)malloc(sizeof(unsigned char) * width * height * 4)))
		exit_error("create_picture malloc error");
	i = 0;
	while (i < width * height)
	{
		if ((i / width < frame_length
			&& (i % width < frame_length - i / width
				|| i % width >= width - (frame_length - i / width)))
		|| (i / width >= height - frame_length
		   && (i % width < frame_length - (i / width - height + frame_length)
				|| i % width >=
					width - (frame_length - (i / width - height + frame_length)))))
			set_channels(picture, i, color);
		else if (i / width >= frame_length && i % width >= frame_length
			&& i/ width < height - frame_length && i % width < width - frame_length)
			set_channels(picture, i, vec4(0.0f, 0.0f, 0.0f, 0.0f));
		else
			set_channels(picture, i, vec4(0.0, 0.5, 0.0, 1.0f));
		i++;
	}
	return (picture);
}
