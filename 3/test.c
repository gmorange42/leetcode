#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max2(int a, int b){
	return a > b ? a : b;
}

int lengthOfLongestSubstring(char * s){
	int arr[128];
	int len = strlen(s);
	for(int i = 0; i < 128; i++){
		arr[i] = -1;
	}
	int ans = 0;
	for(int i = 0, j = 0; j < len; j++){
		i = max2(i, arr[s[j]]+1);
		ans = max2(ans, j - i + 1);
		arr[s[j]] = j;
	}
	return ans;
}

int	main(int ac, char** av)
{
	if (ac == 1)
		return (0);
	printf("The length of %s is %d\n", av[1], lengthOfLongestSubstring(av[1]));
	return (0);
}
