#include <libgcorewar.h>

void	key_escape(void* args)
{
	(void)args;
	glfwSetWindowShouldClose(g_window, GL_TRUE);
}