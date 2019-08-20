#include <libgcorewar.h>

void	carriages_update(t_carriage* carriages)
{
	char i;

	i = 0;
	while (carriages)
	{
		if (carriages->alive)
			g_carriage_array[i].model = g_str_map[carriages->positn]->model;
		else
			g_carriage_array[i].model = g_carriage_array[i].death_position;
		carriages = carriages->next;
		i++;
	}
}