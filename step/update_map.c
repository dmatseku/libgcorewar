#include <libgcorewar.h>

void	non_update_map(unsigned char const *const map, unsigned char const *const owner)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != g_map[i])
		{
			g_map[i] = map[i];
			if (owner[i])
				g_str_map[i]->color = g_str_champions[owner[i] - 1]->color;
			else
				g_str_map[i]->color = vec3(0.8f, 0.8f, 0.8f);
		}
		i++;
	}
}

void	update_map(unsigned char const *const map, unsigned char const *const owner)
{
	size_t			i;
	char const *	tmp;

    i = 0;
	while (i < MEM_SIZE)
	{
        if (map[i] != g_map[i])
        {
            g_map[i] = map[i];
			tmp = my_base(g_map[i]);
			if (!tmp)
				exit_error("itoa error");
			if (!string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height))
				exit_error("string_update error");
            free((void*)tmp);
        }
        if (owner[i])
            (g_str_map[i])->color = g_str_champions[owner[i] - 1]->color;
        else
            (g_str_map[i])->color = vec3(0.8f, 0.8f, 0.8f);
		i++;
	}
}

