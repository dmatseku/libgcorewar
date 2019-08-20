#include <libgcorewar.h>

void	my_memcpy(void* src, void* dst, size_t len)
{
	char* a;
	char* b;

	a = (char*)src;
	b = (char*)dst;
	while (len--)
		a[len] = b[len];
}