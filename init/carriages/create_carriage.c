#include <libgcorewar.h>

static void	set_carriage_height(void)
{
	FT_Glyph glyph = 0;

	FT_Load_Char(g_ftface, 'X', FT_LOAD_RENDER);
	FT_Get_Glyph(g_ftface->glyph, &glyph);
	g_carriage_height = ((FT_BitmapGlyph)glyph)->bitmap.rows;
	FT_Done_Glyph(glyph);
}

void	create_carriage(/*t_carriage* carriages*/)
{
	size_t frame_length;
	t_matrix* matrix;

	matrix = matrix_create(4, 4);
	if (!matrix)
		exit_error("create_matrix error");
	set_carriage_height();
	frame_length = math_length();
	g_v_carriage.picture
			= create_picture_carriege(g_carriage_width, g_carriage_height, frame_length);
	create_carriage_vao(g_carriage_width, g_carriage_height);
	g_v_carriage.model = matrix->mat;
	free(matrix);
}