#include <libgcorewar.h>

void	create_carriage(t_carriage* carriages)
{
//	float d_position_y;
//	float d_position_x;
	char i;
	size_t frame_length = math_length();

//	d_position_y = (BORDER_CENTER_HORISONTAL_Y_2 - (-1.0f + BORDER_LENGTH))
//				   / (g_number_of_champions / 2 + g_number_of_champions % 2 + 1);
//	d_position_x = 1.0f - BORDER_LENGTH - BORDER_CENTER_VERTICAL_X - BORDER_LENGTH / 3;
	i = 0;
	while (carriages)
	{
		g_carriage_array[i].picture
				= create_picture_carriege(g_str_champions[i]->color, g_carriage_width, g_carriage_height, frame_length);
		create_carriage_vao(i, g_carriage_width, g_carriage_height);
		g_carriage_array[i].model = g_str_map[carriages->positn]->model;
		g_carriage_array[i].prev_model = g_carriage_array[i].model;
//		g_carriage_array[i].death_position = vec2(d_position_x * (i % 2 + 1), d_position_y * (i / 2));
		if (!g_carriage_array[i].model)
			exit_error("matrix_to_array error");
		carriages = carriages->next;
		i++;
	}
}