#include <libgcorewar.h>

static void	carriages_counters_update(void)
{
	char*				str;
	size_t				i;

	i = 0;
	while (i < g_number_of_champions)
	{
		str = my_uitoa(g_counts[i]);
		string_update(g_counters[i], str, g_w_width, g_w_height);
		free(str);
		i++;
	}
}


int						out_arena(t_arena *pub);

void	corewar_visual_step(t_arena const *const restrict arena,
							t_carriage * *const restrict carriages)
{
	static uintmax_t	step_nb = 0;
	char const			*str;

	step_nb++;
	if (step_nb < 15000)
		return;
	str = my_uitoa(step_nb);
	if (!str)
		exit_error("my_uitoa error");
	g_update_map(arena->cell, arena->owner);
	string_update(g_str_step_counter, str, g_w_width, g_w_height);
	free((void*)str);
	carriage_list_update(carriages);
	carriages_counters_update();
	step_draw(arena->lastlive);
}