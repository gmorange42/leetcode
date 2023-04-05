#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char*	convert(char* s, int numRows)
{
	char*	ret;
	int	length = strlen(s);
	int	firstGap;
	int	secondGap;
	int	pos;
	bool	switchGap = true;
	int	i = 0;

	if (numRows == 1)
		return (s);

	if (!(ret = malloc(sizeof(char) * (length + 1))))
		return (s);

	firstGap = (numRows - 1) * 2;
	secondGap = 0;
	for (int row = 0; row < numRows; ++row)
	{
		switchGap = true;
		pos = row;
		while (1)
		{
			if (pos < length)
				ret[i++] = s[pos];
			else
				break;

			if (firstGap != 0 && (switchGap || secondGap == 0))
				pos += firstGap;
			else
				pos += secondGap;
			switchGap = !switchGap;
		}
		firstGap -= 2;
		secondGap += 2;
	}
	ret[length] = 0;
	strcpy(s, ret);
	free(ret);
	ret = NULL;
	return (s);
}

int	main(int ac, char** av)
{
	if (ac < 3)
		return (1);

	char *ret;

	ret = convert(av[1], atoi(av[2]));
	printf("%s\n", ret);
	free(ret);
	ret = NULL;

	return (0);
}
