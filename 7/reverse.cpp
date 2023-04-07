#include <iostream>
#include <limits.h>
#include <stdlib.h>

class	Solution {
	public:
		int	reverse(int x) {
			long int	ret = 0;
			long int	to_convert = x;
			int		sign = 1;
			
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
			return (((static_cast<int>(ret)) * sign));
		}
};


int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);

	Solution	soluce;

	std::cout << "The reverse of " << atoi(av[1]) << " is " << soluce.reverse(atoi(av[1])) << std::endl;
	return (0);
}
