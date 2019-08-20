#include <libgcorewar.h>

void	corewar_visual_step(t_arena* arena, t_carriage* carriages)
{
	static uintmax_t	step_nb = 0;
	char*				step_str;

	step_nb++;
	step_str = my_uitoa(step_nb);
	if (!step_str)
		exit_error("my_uitoa error");
	update_map(arena->cell);
	string_update(g_str_step_counter, step_str, g_w_width, g_w_height);

}