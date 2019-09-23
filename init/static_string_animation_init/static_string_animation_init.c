#include <libgcorewar.h>

char	str_static_animation_init(const char init, const double time)
{
	static	double		start;
	char i;

	i = -1;
	if (init)
	{
		start = time;
		return (0);
	}
	else if ((time - start) > STR_S_T)
	{
		g_v_frame[0].color.w = 1.0f;
		g_v_frame[1].color.w = 1.0f;
		g_v_frame[2].color.w = 1.0f;
		g_v_frame[3].color.w = 1.0f;
		g_v_frame[4].color.w = 1.0f;
		g_v_frame[5].color.w = 1.0f;
		g_str_xlogins[0]->color.w = 1.0f;
		g_str_xlogins[1]->color.w = 1.0f;
		g_str_xlogins[2]->color.w = 1.0f;
		g_str_xlogins[3]->color.w = 1.0f;
		g_map_opacity = 1.0f;
		while (++i < 4 + g_number_of_champions)
			g_lines[i].color.w = 1.0f;
		i = -1;
		while (++i < g_number_of_champions)
			g_counters[i]->color.w = 1.0f;
		g_str_corewar->color.w = 1.0f;
		g_str_dead->color.w = 1.0f;
		g_str_cyc_to_die_intro->color.w = 1.0f;
		g_str_speed_intro->color.w = 1.0f;
		g_str_speed->color.w = 1.0f;
		g_str_cyc_to_die->color.w = 1.0f;
		g_map_opacity = 1.0f;
		return (1);
	}
	g_map_opacity = (time - start) / STR_S_T;
	g_v_frame[0].color.w = g_map_opacity;
	g_v_frame[1].color.w = g_map_opacity;
	g_v_frame[2].color.w = g_map_opacity;
	g_v_frame[3].color.w = g_map_opacity;
	g_v_frame[4].color.w = g_map_opacity;
	g_v_frame[5].color.w = g_map_opacity;
	g_str_xlogins[0]->color.w = g_map_opacity;
	g_str_xlogins[1]->color.w = g_map_opacity;
	g_str_xlogins[2]->color.w = g_map_opacity;
	g_str_xlogins[3]->color.w = g_map_opacity;
	while (++i < 4 + g_number_of_champions)
		g_lines[i].color.w = g_map_opacity;
	i = -1;
	while (++i < g_number_of_champions)
		g_counters[i]->color.w = g_map_opacity;
	g_str_corewar->color.w = g_map_opacity;
	g_str_dead->color.w = g_map_opacity;
	g_str_cyc_to_die_intro->color.w = g_map_opacity;
	g_str_speed_intro->color.w = g_map_opacity;
	g_str_speed->color.w = g_map_opacity;
	g_str_cyc_to_die->color.w = g_map_opacity;
	return (0);
}
