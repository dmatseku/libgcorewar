#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char const *const restrict str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	exit_error(char *const restrict str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
