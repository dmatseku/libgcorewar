#include <libgcorewar.h>

void	carriages_update(t_carriage* carriages)
{
	char i;

	i = 0;
	while (carriages)
	{
		g_carriage_array[i].prev_position = g_carriage_array[i].position;
		if (carriages->alive)
			g_carriage_array[i].position = carriages->positn;
		else
			g_carriage_array[i].position = -1;
		carriages = carriages->next;
		i++;
	}
}