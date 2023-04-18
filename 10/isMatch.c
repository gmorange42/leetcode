#include <stdio.h>
#include <stdbool.h>

void	print(char* location, char* s, char* p)
{
	printf("%s S %s\n", location, s);
	printf("%s P %s\n", location, p);
}

bool	isMatch(char* s, char* p)
{
	char	tmp;
	int	point;
	while (*p && *s)
	{
		print("Before", s, p);
		if (*p == '*')
		{
			point = 0;
			print("*", s, p);
			while (*p == '*')
				++p;
			while (*p == '.')
			{
				++p;
				++point;
			}
			tmp = *s;
			while (*s != *p && *s == tmp)
				++s;
			s -= point;
			p -= point;
			print("*", s, p);
//			while (*s != *p && *s)
//				++s;
		}
		else if (*p == '.')
		{
			print(".", s, p);
			++s;
			++p;
			print(".", s, p);
		}
		else
		{
			++s;
			++p;
		}
		puts("");
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
