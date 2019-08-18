#include <libgcorewar.h>
#include <lgs.h>

char	str_corewar_draw_init(char init, double time, size_t index)
{
	static	double		start;
	static	t_string*	string;

	if (init)
	{
		string = string_get_elem(index);
		string->model[0] = 0.0f;
		string->model[5] = 0.0f;
		start = time;
		return (0);
	}
	else if ((time - start) > STRING_COREWAR_INIT_TIME)
	{
		string->model[0] = 1.0;
		string->model[5] = 1.0;
		return (1);
	}
	string->model[0] = (time - start) / STRING_COREWAR_INIT_TIME;
	string->model[5] = string->model[0];
	return (0);
}
