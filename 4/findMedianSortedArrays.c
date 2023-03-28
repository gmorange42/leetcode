#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	double	ret = 0;
	int*	arr;
	int	i = 0;
	int	j = 0;
	int	k = 0;

	if (!(arr = malloc(sizeof(int) * (nums1Size + nums2Size))))
		return (-1);

	while (i < nums1Size && j < nums2Size)
	{
		if (nums1[i] < nums2[j])
		{
			 arr[k] = nums1[i];
			 ++i;
		}
		else
		{
			 arr[k] = nums2[j];
			 ++j;
		}
		++k;
	}

	for (; i < nums1Size; ++i, ++k)
		arr[k] = nums1[i];

	for (; j < nums2Size; ++j, ++k)
		arr[k] = nums2[j];

	if (k % 2 == 1)
		ret = arr[k / 2];
	else
		ret = ((double)arr[k / 2 - 1] + (double)arr[k / 2]) / 2;

	free(arr);
	arr = NULL;
	return (ret);
}

int	main(void)
{
	int	nums1[2] = {1, 3};
	int	nums2[1] = {2};

	printf("The median is %f\n", findMedianSortedArrays(nums1, 2, nums2, 1));

	return (0);
}
