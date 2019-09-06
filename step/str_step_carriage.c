#include <libgcorewar.h>

static void	init_carriage(void)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->prev_x = elem->x;
			elem->prev_y = elem->y;
		}
		elem = elem->next;
	}
}

static void	complete_carriage(void)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->x = g_str_map[elem->position]->translate[12];
			elem->y = g_str_map[elem->position]->translate[13];
		}
		else if (!elem->alive)
			carriage_list_del(&g_carriage_lst, elem);
		elem = elem->next;
	}
}

static void	step_carriage(const double start, const double time)
{
	t_carriage_lst* elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->x = g_str_map[elem->prev_position]->translate[12]
					+ ((g_str_map[elem->position]->translate[12]
					- g_str_map[elem->prev_position]->translate[12]) / STEP_TIME * (time - start));
			elem->y = g_str_map[elem->prev_position]->translate[13]
					+ ((g_str_map[elem->position]->translate[13]
					- g_str_map[elem->prev_position]->translate[13]) / STEP_TIME * (time - start));
		}
		elem = elem->next;
	}
}

char	str_step_carriage(const char init, const double time)
{
	static double	start;

	if (init)
	{
		init_carriage();
		start = time;
		return (0);
	}
	else if (time - start > STEP_TIME)
	{
		complete_carriage();
		return (1);
	}
	step_carriage(start, time);
	return (0);
}

