#include <libgcorewar.h>

char	str_static_animation_init(char init, double time)
{
	static	double		start;

	if (init)
	{
		start = time;
		g_v_frame[0].color.w = 0.0f;
		g_v_frame[1].color.w = 0.0f;
		g_v_frame[2].color.w = 0.0f;
		g_v_frame[3].color.w = 0.0f;
		g_v_frame[4].color.w = 0.0f;
		g_str_corewar->color.w = 0.0f;
		g_str_dead->color.w = 0.0f;
		g_str_corewar->active = 1;
		g_str_dead->active = 1;
		return (0);
	}
	else if ((time - start) > STRING_STATIC_INIT_TIME)
	{
		g_v_frame[0].color.w = 1.0f;
		g_v_frame[1].color.w = 1.0f;
		g_v_frame[2].color.w = 1.0f;
		g_v_frame[3].color.w = 1.0f;
		g_v_frame[4].color.w = 1.0f;
		g_str_corewar->color.w = 1.0f;
		g_str_dead->color.w = 1.0f;
		g_map_opacity = 1.0f;
		return (1);
	}
	g_map_opacity = (time - start) / STRING_STATIC_INIT_TIME;
	g_v_frame[0].color.w = g_map_opacity;
	g_v_frame[1].color.w = g_map_opacity;
	g_v_frame[2].color.w = g_map_opacity;
	g_v_frame[3].color.w = g_map_opacity;
	g_v_frame[4].color.w = g_map_opacity;
	g_str_corewar->color.w = g_map_opacity;
	g_str_dead->color.w = g_map_opacity;
	return (0);
}
