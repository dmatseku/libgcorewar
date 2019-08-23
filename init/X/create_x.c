#include <libgcorewar.h>

void	create_x(void)
{
	t_matrix* matrix;

	create_x_shader_program();
	matrix = m_translate_new(vec4(1.0f - MENU_WIDTH + (1.0f - MENU_WIDTH) / 12,
			g_str_champions[0]->model[13], 0.0f, 0.0f));
	g_x.picture = create_picture_x(STRING_CHAMPION_FONTSIZE * 0.5);
	create_x_vao(STRING_CHAMPION_FONTSIZE * 0.5);
	g_x.model = matrix_to_array(matrix);
	g_x.draw = 0;
	g_x.color = g_str_champions[0]->color;
	matrix_free(matrix);
}
