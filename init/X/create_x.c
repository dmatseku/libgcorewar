#include <libgcorewar.h>

static size_t	get_max_width(void)
{
	char nb;
	size_t res;

	nb = 0;
	res = 0;
	while (nb < g_number_of_champions)
	{
		if (g_str_champions[nb]->image_width > res)
			res = g_str_champions[nb]->image_width;
		nb++;
	}
	return (res);
}

void	create_x(void)
{
	t_matrix*	matrix;

	create_x_shader_program();
	matrix = m_translate_new(vec4(1.0f - MENU_WIDTH / 2
				- (0.25 * STRING_CHAMPION_FONTSIZE + X_DISTANCE + 0.5f * get_max_width()) / g_w_width * 2,
			g_str_champions[0]->translate[13], 0.0f, 1.0f));
	g_x.picture = create_picture_x(STRING_CHAMPION_FONTSIZE * 0.5);
	create_x_vao(STRING_CHAMPION_FONTSIZE * 0.5);
	g_x.model = matrix->mat;
	g_x.draw = 0;
	g_x.init = 1;
	g_x.color = g_str_champions[0]->color;
	g_x.color.w = 0;
	g_x.position = 1;
	free(matrix);
}