#include <stdio.h>
#include <stdbool.h>

bool	isMatch(char* s, char* p)
{
	while (*p && *s)
	{
		if (*p == '*')
		{
			while (*p == '*')
			{
				++p;
				if (*p == '.')
					++p;
			}
			while (*s != *p && *s)
				++s;
		}
		else if (*p == '.')
		{
			++s;
			++p;
		}
		else
		{
			++s;
			++p;
		}
	}
	if (*s == *p)
		return (true);
	return (false);
}

int	main(int ac, char** av)
{
	if (ac < 3)
		return (1);
	if (isMatch(av[1], av[2]))
		printf("%s is match with %s\n", av[1], av[2]);
	else
		puts("NO MATCH");
	return (0);
}
