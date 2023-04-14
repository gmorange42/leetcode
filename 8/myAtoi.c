#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int	myAtoi(char *s)
{
	unsigned long int	ret = 0;
	bool			sign = true;

	for (;*s == ' '; ++s)
		;
	if (*s == '+' || *s == '-')
	{
		sign = (*s == '+') ? true : false;
		++s;
	}
	for (; *s >= '0' && *s <= '9' && ret < INT_MAX; ++s)
	{
		ret *= 10;
		ret += (*s - 48);
	}
	if (ret > INT_MAX && sign)
		return (INT_MAX);
	else if (ret > (unsigned int)(INT_MAX) + 1 && !sign)
		return (INT_MIN);
	if (!sign)
		ret *= -1;
	return (ret);
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);
	printf("myAtoi(%s) -> %d\n", av[1], myAtoi(av[1]));
	return (0);
}
