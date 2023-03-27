#include <iostream>
#include <vector>

class	Solution {
	public:
		double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
		{
			double			ret = 0;
			std::vector<int>	arr;	
			std::vector<int>::iterator	nums1It = nums1.begin();
			std::vector<int>::iterator	nums2It = nums2.begin();
			std::vector<int>::iterator	nums1End = nums1.end();
			std::vector<int>::iterator	nums2End = nums2.end();

			while (nums1It != nums1End && nums2It != nums2End)
			{
				if (*nums1It < *nums2It)
					arr.push_back(*nums1It++);
				else
					arr.push_back(*nums2It++);
			}

			while (nums1It != nums1End)
				arr.push_back(*nums1It++);

			while (nums2It != nums2End)
				arr.push_back(*nums2It++);

			if (arr.size() % 2 == 1)
				ret = static_cast<double>(arr[arr.size() / 2]);
			else
				ret = (static_cast<double>(arr[arr.size() / 2 - 1]) + static_cast<double>(arr[arr.size() / 2])) / 2;

			return (ret);
		}
};

int	main(void)
{
	Solution		soluce;
	std::vector<int>	nums1;
	std::vector<int>	nums2;

	nums1.push_back(0);
	nums1.push_back(0);

	nums2.push_back(0);
	nums2.push_back(0);

	std::cout << "The median of nums1 and nums2 is " << soluce.findMedianSortedArrays(nums1, nums2) << std::endl;

	return (0);
}
