#include <libgcorewar.h>
#include <stdlib.h>

static t_carriage_lst*	find_elem(const unsigned int id)
{
	t_carriage_lst* tmp;

	tmp = g_carriage_lst;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
	return (tmp);
}

static void	create_elem(t_carriage const *const restrict carriage)
{
	t_carriage_lst* tmp;

	tmp = (t_carriage_lst*)malloc(sizeof(t_carriage_lst));
	if (!tmp)
		exit_error("malloc error");
	tmp->id = carriage->id;
	tmp->alive = 1;
	tmp->player = carriage->player;
	tmp->position = carriage->posit;
	tmp->prev_position = carriage->posit;
	tmp->x = g_str_map[tmp->position]->position.x;
	tmp->y = g_str_map[tmp->position]->position.y;
	g_counts[tmp->player - 1]++;
	carriage_list_add(&g_carriage_lst, tmp);
}

static void free_carriage(t_carriage *restrict del)
{
	del->prev->next = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del);
}

static void	free_first_carriage(t_carriage * *restrict elem)
{
	t_carriage *const tmp = *elem;

	*elem = (*elem)->next;
	if (*elem)
        (*elem)->prev = 0;
	free(tmp);
}

void	carriage_list_update(t_carriage * *restrict carriages)
{
	t_carriage_lst *restrict	tmp;
	t_carriage*					elem;

	elem = (t_carriage*)*carriages;
	while (elem)
	{
		tmp = find_elem(elem->id);
		if (!tmp)
			create_elem(elem);
		else if (!elem->alive)
		{
			tmp->alive = 0;
			if (elem == *carriages)
			{
				elem = elem->next;
				free_first_carriage(carriages);
				continue ;
			}
			else
				free_carriage(elem);
			g_counts[tmp->player - 1]--;
		}
		else
		{
			tmp->prev_position = tmp->position;
			tmp->position = elem->posit;
			tmp->x = g_str_map[tmp->position]->position.x;
			tmp->y = g_str_map[tmp->position]->position.y;
		}
		elem = elem->next;
	}
}
