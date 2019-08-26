#include <libgcorewar.h>

static t_carriage_lst*	find_elem(unsigned int id)
{
	t_carriage_lst* tmp;

	tmp = g_carriage_lst;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
	return (tmp);
}

static void	create_elem(t_carriage* carriage)
{
	t_carriage_lst *const tmp = (t_carriage_lst*)malloc(sizeof(t_carriage_lst));

	if (!tmp)
		exit_error("malloc error");
	tmp->id = carriage->id;
	tmp->alive = 1;
	tmp->player = carriage->player;
	tmp->position = carriage->positn;
	tmp->prev_position = carriage->positn;
	tmp->x = g_str_map[tmp->position]->translate[12];
	tmp->y = g_str_map[tmp->position]->translate[13];
	carriage_list_add(&g_carriage_lst, tmp);
}

void	carriage_list_update(t_carriage* carriages)
{
	t_carriage_lst* tmp;

	while (carriages)
	{
		tmp = find_elem(carriages->id);
		if (!tmp)
			create_elem(carriages);
		else
		{
			tmp->position = carriages->positn;
			tmp->alive = tmp->alive;
			tmp->x = g_str_map[tmp->position]->translate[12];
			tmp->y = g_str_map[tmp->position]->translate[13];
		}
		carriages = carriages->next;
	}
}
