#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool	isPalindrome(int x)
{
	if (x < 0)
		return (false);
	int	tmp = x;
	long int	ret = 0;
	while (x > 0)
	{
		ret = (ret * 10) + (x % 10);
		x /= 10;
	}
	return(ret == tmp);
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);
	bool	ret = isPalindrome(atoi(av[1]));

	if (ret)
		printf("%s is a palindrome\n", av[1]);
	else
		printf("%s is not a palindrome\n", av[1]);
	return (0);
}
