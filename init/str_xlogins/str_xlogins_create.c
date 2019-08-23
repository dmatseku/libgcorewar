#include <libgcorewar.h>

void	str_xlogins_create(void)
{
	const float	d_x = MENU_WIDTH / 5;
	const float d_y = (-1.0f - SPLITER_Y_4) / 6;

	g_str_xlogins[0] = string_get_elem(
			string_create("okaramel", 1.0f - MENU_WIDTH + d_x, SPLITER_Y_4 + d_y * 2 + d_y / 2,
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[1] = string_get_elem(
			string_create("dmatseku", 1.0f - MENU_WIDTH + d_x * 2, SPLITER_Y_4 + d_y * 2 + d_y / 2,
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[2] = string_get_elem(
			string_create("ashypilo", 1.0f - MENU_WIDTH + d_x * 3, SPLITER_Y_4 + d_y * 2 + d_y / 2,
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[3] = string_get_elem(
			string_create("vyunak", 1.0f - MENU_WIDTH + d_x * 4, SPLITER_Y_4 + d_y * 2 + d_y / 2,
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	create_line_vao(0, 1.0f - MENU_WIDTH + d_x, SPLITER_Y_4 + d_y * 3 + d_y / 2);
	g_lines[0].color = vec4(0.850980392156863f, 0.325490196078431f, 0.309803921568627f, 0.0f);
	create_line_vao(1, 1.0f - MENU_WIDTH + d_x * 2, SPLITER_Y_4 + d_y * 3 + d_y / 2);
	g_lines[1].color = vec4(1.0f, 0.654901960784314f, 0.0f, 0.0f);
	create_line_vao(2, 1.0f - MENU_WIDTH + d_x * 3, SPLITER_Y_4 + d_y * 3 + d_y / 2);
	g_lines[2].color = vec4(0.36078431372549f, 0.72156862745098f, 0.36078431372549f, 0.0f);
	create_line_vao(3, 1.0f - MENU_WIDTH + d_x * 4, SPLITER_Y_4 + d_y * 3 + d_y / 2);
	g_lines[3].color = vec4(0.258823529411765f, 0.545098039215686f, 0.792156862745098f, 0.0f);
}
