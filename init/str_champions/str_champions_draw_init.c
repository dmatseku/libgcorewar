#include <libgcorewar.h>

static void	set_active(void)
{
	char			i;

	i = 0;
	while (i < g_number_of_champions)
	{
		g_str_champions[i]->active = 1;
		i++;
	}
}

static void step_champions(char* nb, double time, double start)
{
	char			dnb;

	dnb = (char)((time - start) / (STRING_CHAMPION_INIT_TIME
			/ g_number_of_champions));
		while (*nb <= dnb)
	{
		g_str_champions[*nb]->active = 1;
		(*nb)++;
	}
}

char	str_champions_draw_init(char init, double time)
{
	static double	start;
	static char		nb;

	if (init && STRING_CHAMPION_INIT_TIME >= 0.1)
	{
		start = time;
		nb = 0;
		return (0);
	}
	else if (STRING_CHAMPION_INIT_TIME < 0.1
	|| time - start > STRING_CHAMPION_INIT_TIME || nb == g_number_of_champions)
	{
		set_active();
		return (1);
	}
	step_champions(&nb, time, start);
	return (0);
}
