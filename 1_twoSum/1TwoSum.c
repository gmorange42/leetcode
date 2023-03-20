#include <stdio.h>
#include <stdlib.h>

int*	twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int*	ret = malloc(sizeof(int) * 2);
	if (ret == NULL)
		return (NULL);
	*returnSize = 2;

	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				ret[0] = i;
				ret[1] = j;
				break;
			}
		}
	}
	return (ret);
}

int	main(void)
{
	int	nums[] = {2, 7, 11, 15};
	int*	ret = NULL;
	int	returnSize = 0;

	ret = twoSum(nums, 4, 9, &returnSize);
	printf("ret = [%d, %d] returnSize = %d\n", ret[0], ret[1], returnSize);

	free(ret);
	ret = NULL;
	return (0);
}
