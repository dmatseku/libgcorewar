#include <libgcorewar.h>

static char	*create_array(uintmax_t n)
{
	size_t      i;
	uintmax_t   j;

	i = 1;
	j = 1;
	while (n / j > 9)
	{
		j *= 10;
		i++;
	}
	return ((char*)malloc(sizeof(char) * (i + 1)));
}

static void	set_res(char **res, uintmax_t i, uintmax_t n)
{
	int j;

	j = 0;
	while (i > 0)
	{
		(*res)[j] = (char)(n / i + 48);
		n = n % i;
		i /= 10;
		j++;
	}
	(*res)[j]  = '\0';
}

char		*my_uitoa(uintmax_t n)
{
	char        *res;
	uintmax_t   i;

	i = 1;
	res = create_array(n);
	if (!res)
		return (0);
	while (n / i > 9)
		i *= 10;
	set_res(&res, i, n);
	return (res);
}

static char	convert_to_char(unsigned char nb)
{
	if (nb <= 9)
		return (nb + 48);
	return ('A' + nb - 10);
}

char		*my_base(unsigned char nb)
{
	char    *res;
	res = (char*)malloc(sizeof(char) * 3);
	if (!res)
		exit_error("malloc error");
	res[1] = convert_to_char(nb % 16);
	nb /= 16;
	res[0] = convert_to_char(nb % 16);
	res[2] = '\0';
	return (res);
}