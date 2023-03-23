#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int	lengthOfLongestSubstring(char* s)
{
	int	length = 0;
	int	max = 0;
	bool	save[256];

	bzero(&save, 256);

	for (int i = 0; s[i]; ++i)
	{
		if (!save[s[i]])
		{
			save[s[i]] = true;
			++length;
			printf("In %c %d %d\n", s[i], length, max);
		}
		else
		{
			if (max < length)
				max = length;
			length = 0;
			bzero(&save, 256);
			printf("Else %c %d %d\n", s[i], length, max);
			--i;
		}
	}

	if (length > max)
		return (length);

	return	(max);
}

int	main(int ac, char** av)
{
	if (ac == 1)
		return (0);
	printf("The length of %s is %d\n", av[1], lengthOfLongestSubstring(av[1]));
	return (0);
}
