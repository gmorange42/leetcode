#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char*	longestPalindrome(char* s)
{
	char*	ret;
	int	begin;
	int	end;
	int	size;
	int	max = 0;

	if (!s || strlen(s) == 0)
		return (s);

	ret = malloc(strlen(s) + 1);

	if (!ret)
		return(s);

	for (int i = 0; s[i + 1]; ++i)
	{
		if ((s[i - 1] == s[i + 1]) || s[i] == s[i +1])
		{
			begin = 1;
			end = 1;
			size = 1;
			if (s[i] == s[i + 1])
			{
				--begin;
				++end;
				++size;
			}
			while (begin < i && s[i + end + 1] && s[i - begin] == s[i + end])
			{
				++begin;
				++end;
				size += 2;
			}
			if (size > max)
			{
				strncpy(ret, &s[i - begin], size);
				ret[size] = 0;
				max = size;
			}
		}
	}

	if (ret)
		return(ret);

	return(s);
}

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);

	char*	str;
	str = longestPalindrome(av[1]);
	printf("The longest palindrome in \"%s\" is \"%s\"\n", av[1], str);
	free(str);
	str = NULL;

	return(0);
}
