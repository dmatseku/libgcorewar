#include <libgcorewar.h>

void	update_map(unsigned char const *const map)
{
	size_t i;
	char* tmp;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != g_map[i])
		{
			g_map[i] = map[i];
			tmp = my_base(g_map[i]);
			if (!tmp)
				exit_error("itoa error");
			if (!string_update(g_str_map[i], tmp, g_w_width, g_w_height))
				exit_error("string_update error");
			if (g_map[i] != 0)
				g_str_map[i]->color = vec3(0.6f, 0.6f, 0.0f);
			else
				g_str_map[i]->color = vec3(0.5f, 0.5f, 0.5f);
			free(tmp);
		}
		i++;
	}
}

