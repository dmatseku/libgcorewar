#include <libgcorewar.h>
#include <stdlib.h>

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
	g_counts[tmp->player - 1]++;
	carriage_list_add(&g_carriage_lst, tmp);
}

static void	free_carriage(t_carriage* prev, t_carriage* elem)
{
	prev->next = elem->next;
	free(elem);
}

static void	free_first_carriage(t_carriage** elem)
{
	t_carriage* tmp;

	tmp = *elem;
	*elem = (*elem)->next;
	free(tmp);
}

void	carriage_list_update(t_carriage** carriages)
{
	t_carriage_lst* tmp;
	t_carriage*		prev_carriage;
	t_carriage*		elem;

	prev_carriage = 0;
	elem = *carriages;
	while (elem)
	{
		tmp = find_elem(elem->id);
		if (!tmp)
			create_elem(elem);
		else if (!elem->alive)
		{
			tmp->alive = 0;
			if (!prev_carriage)
			{
				elem = elem->next;
				free_first_carriage(carriages);
				continue ;
			}
			else
				free_carriage(prev_carriage, elem);
			g_counts[tmp->player - 1]--;
		}
		else
		{
			tmp->prev_position = tmp->position;
			tmp->position = elem->positn;
			tmp->x = g_str_map[tmp->position]->translate[12];
			tmp->y = g_str_map[tmp->position]->translate[13];
		}
		prev_carriage = elem;
		elem = elem->next;
	}
}
