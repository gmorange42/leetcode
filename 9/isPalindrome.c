#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int	findDivider(int x)
{
	int	ret = 1;
	x /= 10;
	
	while (x > 0)
	{
		ret *= 10;
		x /= 10;
//		printf("%d %d\n", ret, x);
	}
	return (ret);
}

bool	isPalindrome(int x)
{
	if (x < 0)
		return (false);
	if (x == 0)
		return (true);

//	int	length = floor(log10(abs(x))) + 1;
	int	divider = findDivider(x);
//	int	first = x / divider;
//	int	last = x % 10;

	while (divider != 10)
	{
		printf("(first %d) (last%d)\n", (x / divider), ( x % 10));
		if ((x / divider) != (x % 10))
			return (false);
		x %= divider;
		x /= 10;
		divider /= 10;
		printf("In While %d %d\n", x, divider);
	}
//	if (length == 1)
//		return (true);



	return (true);
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);
	bool	ret = isPalindrome(atoi(av[1]));

	printf("divider of %s is %d\n", av[1], findDivider(atoi(av[1])));
	if (ret)
		printf("%s is a palindrome\n", av[1]);
	else
		printf("%s is not a palindrome\n", av[1]);
	return (0);
}
