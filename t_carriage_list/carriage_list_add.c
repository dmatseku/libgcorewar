#include <libgcorewar.h>

void	carriage_list_add(t_carr_lst* *const restrict lst, t_carr_lst *const elem)
{
	t_carr_lst* tmp;

	if (!*lst)
	{
		*lst = elem;
		elem->prev = 0;
		elem->next = 0;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->prev = tmp;
	elem->next = 0;
}
