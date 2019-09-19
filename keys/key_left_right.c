#include <libgcorewar.h>
#include <libglKH.h>

void	key_left(void* args)
{
	char*		tmp;
	char		str[5];
	char		i;

	(void)args;
	g_step_time += DELTA_STEP;
	if (g_step_time > 2.0f)
		g_step_time = 2.0f;
	tmp = my_uitoa((unsigned int)(50.0f * (2.0f - g_step_time)));
	if (!tmp)
		exit_error("my_uitoa error");
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	str[i] = '%';
	str[i + 1] = 0;
	string_update(g_str_speed, str, g_w_width, g_w_height);
	free(tmp);
}

void	key_right(void* args)
{
	char*		tmp;
	char		str[5];
	char		i;

	(void)args;
	g_step_time -= DELTA_STEP;
	if (g_step_time < 0.0f)
		g_step_time = 0.0f;
	tmp = my_uitoa((unsigned int)(50.0f * (2.0f - g_step_time)));
	if (!tmp)
		exit_error("my_uitoa error");
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	str[i] = '%';
	str[i + 1] = 0;
	string_update(g_str_speed, str, g_w_width, g_w_height);
	free(tmp);
}

char	key_right_condition(void)
{
	return (!g_glkeys_states[GLFW_KEY_LEFT]);
}

