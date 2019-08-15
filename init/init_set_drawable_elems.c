#include <libgcorewar.h>

void	init_set_drawable_elems(void)
{
	create_frame_shader_program();
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao, .x1 = -1.0f, .x2 = 1.0f, .y1 = -1.0f, .y2 = -0.9f});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 1, .x1 = -1.0f, .x2 = 1.0f, .y1 = 1.0f, .y2 = 0.9f});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 2, .x1 = -1.0f, .x2 = 1.0f, .y1 = 0.3f, .y2 = 0.5f});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 3, .x1 = -1.0f, .x2 = -0.9f, .y1 = -1.0f, .y2 = 1.0f});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 4, .x1 = 1.0f, .x2 = 0.9f, .y1 = -1.0f, .y2 = 1.0f});
	create_frame_vao((t_create_frame_vao_args)
	{.vao = g_frame_vao + 5, .x1 = 0.3f, .x2 = 0.5f, .y1 = -1.0f, .y2 = 1.0f});
	draw_arena();
}