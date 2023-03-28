#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int	lengthOfLongestSubstring(char* s)
{
	int	length = 0;
	int	max = 0;
	bool	save[128];
	void*	index[128];

	bzero(&save, 128);
	bzero(&index, 128);

	for (char* ptr = s; *ptr; ptr += sizeof(char))
	{
		if (!save[*ptr])
		{
			save[*ptr] = true;
			index[*ptr] = ptr;
			++length;
		}
		else
		{
			if (max < length)
				max = length;
			length = 0;
			ptr = index[*ptr];
			bzero(&save, 128);
			bzero(&index, sizeof(int) * 128);
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
