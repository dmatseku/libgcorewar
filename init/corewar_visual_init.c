#include <libgcorewar.h>

char	corewar_visual_init(t_champ* champions, t_arena* arena, t_carriage** carriages)
{
	if (!glfwInit())
		exit_error("glfw init error");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	g_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "", 0, 0);
	glfwMakeContextCurrent(g_window);
	glfwSwapInterval(0);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		exit_error("glew init error");
	if (!string_init(FONT_PATH))
		exit_error("string init error");
//	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetWindowPos(g_window, 50, 50);
	glfwGetFramebufferSize(g_window, &g_w_width, &g_w_height);
	glViewport(0, 0, g_w_width, g_w_height);
	init_set_drawable_elems(champions, arena, carriages);
	return (1);
}
