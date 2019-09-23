#include <libgcorewar.h>

static char*		create_tmp_string(t_champ* champion)
{
	char*	str = (char*)malloc(sizeof(char) * (my_strlen(champion->name) + 18));
	int		i;

	my_strncat(str, "WINNER: \"", 9);
	i = 9;
	while (champion->name[i - 9])
	{
		str[i] = champion->name[i - 9];
		i++;
	}
	my_strncat(str + i, "\", id: ", 7);
	str[i + 7] = champion->id + 48;
	str[i + 8] = 0;
	return (str);
}

static t_string*	create_string(t_champ* champion)
{
	t_string*	res;
	char*		str = create_tmp_string(champion);

	res = string_get_elem(string_create_nospace(str, vec3(0.0f, 0.0f, 0.0f),
			WI_FS, vec4(1.0f, 1.0f, 1.0f, 1.0f), g_window));
	res->color.w = 0;
	free(str);
	return (res);
}

void	corewar_visual_destroy(t_champ* champion)
{
	g_str_winner = create_string(champion);
	destroy_draw();
	glfwTerminate();
}