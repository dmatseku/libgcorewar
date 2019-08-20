#include <libgcorewar.h>

char	str_step_carriage(char init, double time)
{
	static	double start;

	if (init)
	{
		start = time;
		return (1);
	}
	else if (time - start > STEP_TIME)
	{

	}
}

