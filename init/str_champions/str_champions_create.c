#include <libgcorewar.h>


static void champ_length(t_champ* champions)
{
	g_number_of_champions = 0;
	while (champions)
	{
		g_number_of_champions++;
		champions = champions->next;
	}
}

static t_vector*	set_colors(void)
{
	t_vector *const restrict vectors = (t_vector*)malloc(sizeof(t_vector) * 4);

	vectors[0] = vec4(1.0, 0.0784, 0.0784, 1.0);
	vectors[1] = vec4(0.0, 0.0, 1.0, 1.0);
	vectors[2] = vec4(0.0, 0.7607, 0.2156, 1.0);
	vectors[3] = vec4(0.5, 0.5, 0.0, 1.0);
	return (vectors);
}

static void	create_string(size_t i, t_vector* colors, float y, char* name)
{
	char*	tmp;

	tmp = 0;
	if (ft_strlen(name) > STRING_CHAMPION_MAX_LENGTH)
	{
		tmp = name;
		name = (char*)malloc(sizeof(char) * STRING_CHAMPION_MAX_LENGTH + 1);
		if (!name)
			exit_error("create string malloc error");
		ft_strncat(name, tmp, STRING_CHAMPION_MAX_LENGTH - 3);
		my_memset(name + STRING_CHAMPION_MAX_LENGTH - 3, '.', 3);
		name[STRING_CHAMPION_MAX_LENGTH] = 0;
	}
	g_str_champions[i] = string_get_elem(string_create(name,
		0.5f + BORDER_CENTER_VERTICAL_X / 2, y,
		STRING_CHAMPION_FONTSIZE, colors[i % 4], g_window));
	g_str_champions[i]->active = 0;
	if (tmp)
		free(name);
}

void	str_champions_create(t_champ* champions)
{
	size_t		i;
	float		dy;
	float		y;
	t_vector*	colors;

	champ_length(champions);
	g_str_champions = (t_string**)malloc(sizeof(t_string*) * g_number_of_champions);
	colors = set_colors();
	if (!g_str_champions || !colors)
		exit_error("str_champions malloc error");
	dy = (float)(STRING_CHAMPION_FONTSIZE) / g_w_height + STRING_CHAMPION_SPLITSIZE;
	y = BORDER_CENTER_HORISONTAL_Y_1 - STRING_CHAMPION_SPLITSIZE
			- ((float)(STRING_CHAMPION_FONTSIZE) / g_w_height / 2);
	i = 0;
	while (i < g_number_of_champions)
	{
		create_string(i, colors, y, champions->name);
		champions = champions->next;
		y -= dy;
		i++;
	}
	free(colors);
}