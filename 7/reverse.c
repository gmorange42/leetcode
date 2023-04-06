#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	reverse(int x)
{
	long int	ret = 0;
	long int	to_convert = x;
	int	sign = 1;
	
	if (to_convert < 0)
		sign *= -1;
	to_convert *= sign;
	while (to_convert > 0)
	{
		ret *= 10;
		ret += to_convert % 10;
		if ((sign > 0 && ret > INT_MAX) || (sign < 0 && ret > ((long int)INT_MAX) + 1))
			return (0);
		to_convert /= 10;
	}
	return (((int)ret * sign));
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);
	printf("The reverse of %d is %d\n", atoi(av[1]), reverse(atoi(av[1])));
	return (0);
}
