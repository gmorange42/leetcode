#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool	isPalindrome(int x)
{
	if (x < 0)
		return (false);
	if (x = 0)
		return (true);

	int	first;
	int	last;
	int	length = floor(log10(abs(x))) + 1;

	while (length < 1)
	{
	}

	return (true);
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);
	isPalindrome(atoi(av[1]));
	return (0);
}
