#include <libgcorewar.h>

static void	set_y_coord(void)
{
	float y;

	y = -1.0f - (-1.0f - SPLITER_Y_4) / 2
		+ (float)(g_str_xlogins[0]->image_height + XLOGINS_DISTANCE + 1) / g_w_height
		- 0.5f * g_str_xlogins[0]->image_height / g_w_height * 2;
	g_str_xlogins[0]->position.y = y;
	g_str_xlogins[1]->position.y = y;
	g_str_xlogins[2]->position.y = y;
	g_str_xlogins[3]->position.y = y;
}

static void set_lines(void)
{
	const float	d_x = MENU_WIDTH / 5;
	float		y1;

	y1 = -1.0f - (-1.0f - SPLITER_Y_4) / 2
		 + (float)(g_str_xlogins[0]->image_height + XLOGINS_DISTANCE + 1) / g_w_height
		 - (0.5f + XLOGINS_DISTANCE + g_str_xlogins[0]->image_height) / g_w_height * 2;
	create_line_vao(0, 1.0f - MENU_WIDTH + d_x, y1, g_str_xlogins[0]->image_width + 20);
	g_lines[0].color = vec4(0.850980392156863f, 0.325490196078431f, 0.309803921568627f, 0.0f);
	create_line_vao(1, 1.0f - MENU_WIDTH + d_x * 2, y1, g_str_xlogins[1]->image_width + 20);
	g_lines[1].color = vec4(1.0f, 0.654901960784314f, 0.0f, 0.0f);
	create_line_vao(2, 1.0f - MENU_WIDTH + d_x * 3, y1, g_str_xlogins[2]->image_width + 20);
	g_lines[2].color = vec4(0.36078431372549f, 0.72156862745098f, 0.36078431372549f, 0.0f);
	create_line_vao(3, 1.0f - MENU_WIDTH + d_x * 4, y1, g_str_xlogins[3]->image_width + 20);
	g_lines[3].color = vec4(0.258823529411765f, 0.545098039215686f, 0.792156862745098f, 0.0f);
}

void	str_xlogins_create(void)
{
	const float	d_x = MENU_WIDTH / 5;

	g_str_xlogins[0] = string_get_elem(
			string_create("okaramel", vec4(1.0f - MENU_WIDTH + d_x, 0.0f, 0.0f, 1.0f),
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[1] = string_get_elem(
			string_create("dmatseku", vec4(1.0f - MENU_WIDTH + d_x * 2, 0.0f, 0.0f, 1.0f),
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[2] = string_get_elem(
			string_create("ashypilo", vec4(1.0f - MENU_WIDTH + d_x * 3, 0.0f, 0.0f, 1.0f),
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	g_str_xlogins[3] = string_get_elem(
			string_create("vyunak", vec4(1.0f - MENU_WIDTH + d_x * 4, 0.0f, 0.0f, 1.0f),
					XLOGINS_FONTSIZE, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
	set_y_coord();
	set_lines();
}
