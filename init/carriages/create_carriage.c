#include <libgcorewar.h>

//static void	set_coords(const char i)
//{
//	const float d_x = MENU_WIDTH / (MAX_CARRIAGES + 1);
//	float d_y = (SPLITER_Y_3 - SPLITER_Y_4 - SPLITER_HEIGHT) / 3;
//
//	g_carriage_array[i].death_model[12] = 1.0f - MENU_WIDTH + d_x * (i + 1) + d_x * (MAX_CARRIAGES - g_number_of_champions) / 2;
//	g_carriage_array[i].death_model[13] = SPLITER_Y_3 - d_y * 2 - 1.0f / g_w_height * 2;
//}

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
//	char i;
	size_t frame_length;
	t_matrix* matrix;

//	i = 0;
	matrix = matrix_create(4, 4);
	if (!matrix)
		exit_error("create_matrix error");
	set_carriage_height();
	frame_length = math_length();
//	while (carriages)
//	{
		g_v_carriage.picture
				= create_picture_carriege(g_carriage_width, g_carriage_height, frame_length);
		create_carriage_vao(g_carriage_width, g_carriage_height);
		g_v_carriage.model = matrix->mat;
//		if (!g_carriage_array[i].model)
//			exit_error("malloc error");
//		my_memcpy(g_carriage_array[i].model, g_str_map[carriages->positn]->translate, 16 * sizeof(float));
//		g_carriage_array[i].model[13] -= 1.0f / g_w_height * 2;
//		g_carriage_array[i].death_model = matrix->mat;
//		set_coords(i);
//		g_carriage_array[i].alive = 1;
//		g_carriage_array[i].position = carriages->positn;
//		g_carriage_array[i].prev_position = g_carriage_array[i].position;
//		carriages = carriages->next;
//		i++;
//	}
	free(matrix);
}