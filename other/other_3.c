#include <libgcorewar.h>

void	my_memcpy(void *const src, void const *const dst, size_t len)
{
	char *const			a = (char*)src;
	char const *const	b = (char*)dst;

	while (len--)
		a[len] = b[len];
}