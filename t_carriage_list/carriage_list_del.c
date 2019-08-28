#include <libgcorewar.h>

void	carriage_list_del(t_carriage_lst** lst, t_carriage_lst* elem)
{
	if (*lst == elem)
	{
		*lst = (*lst)->next;
		if (*lst)
			(*lst)->prev = 0;
		free(elem);
		return ;
	}
	elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}