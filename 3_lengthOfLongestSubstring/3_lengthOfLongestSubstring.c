#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct data
{
	bool	save[128];
	int	index[128];
}	data;

int	lengthOfLongestSubstring(char* s)
{
	int	length = 0;
	int	max = 0;
	bool	save[128];
	data	ssd;


	bzero(&ssd.save, 128);
	bzero(&ssd.index, sizeof(int) * 128);

	for (int i = 0; s[i]; ++i)
	{
		if (!ssd.save[s[i]])
		{
			ssd.save[s[i]] = true;
			ssd.index[s[i]] = i;
			++length;
		}
		else
		{
			if (max < length)
				max = length;
			length = 0;
			i = ssd.index[s[i]];
			bzero(&ssd.save, 128);
			bzero(&ssd.index, sizeof(int) * 128);
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
