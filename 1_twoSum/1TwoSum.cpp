#include <iostream>
#include <vector>

class Solution {
	public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			int size = nums.size();
			for (int i = 0; i < size; ++i)
			{
				for (int j = i + 1; j < size; ++j)
				{
					if (nums[i] + nums[j] == target)
						return {i, j};
				}
			}
			return {};
		}
};

int	main(void)
{
	Solution object;
	std::vector<int> Vectest;
	Vectest.push_back(3);
	Vectest.push_back(2);
	Vectest.push_back(4);

	std::vector<int> soluce = object.twoSum(Vectest, 6);
	for (std::vector<int>::iterator it = soluce.begin(); it != soluce.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "Sum = " << Vectest[soluce[0]] + Vectest[soluce[1]] << std::endl;
	return (0);
}
