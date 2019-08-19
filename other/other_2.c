#include <libgcorewar.h>

static char     convert_to_char(size_t nb, size_t uplow)
{
	if (nb <= 9)
		return ((char)(nb + 48));
	if (uplow)
		return ((char)('A' + nb - 10));
	return ((char)('a' + nb - 10));
}

static size_t	ft_uintlenbase(uintmax_t elem, size_t base)
{
	size_t res;

	res = 1;
	while (elem >= base)
	{
		elem /= base;
		res++;
	}
	return (res);
}

static void		reverse(char *res, int tmp)
{
	int     tmp1;
	char    c;

	tmp1 = 0;
	while (tmp1 <= tmp / 2)
	{
		c = res[tmp1];
		res[tmp1] = res[tmp - tmp1];
		res[tmp - tmp1] = c;
		tmp1++;
	}
}

char            *my_itoabase(uintmax_t nb, size_t base, size_t uplow)
{
	char    *res;
	int     tmp;
	int     tmp1;
	char    c;

	tmp = 0;
	res = (char*)malloc(sizeof(char) * (ft_uintlenbase(nb, base) + 1));
	if (!res)
		exit_error("malloc error");
	while (nb >= base)
	{
		res[tmp] = convert_to_char((size_t)(nb % base), uplow);
		nb /= base;
		tmp++;
	}
	res[tmp] = convert_to_char((size_t)nb, uplow);
	res[tmp + 1] = 0;
	reverse(res, tmp);
	return (res);
}
