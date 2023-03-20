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
	Solution test;
	std::vector<int> pouet;
	pouet.push_back(3);
	pouet.push_back(2);
	pouet.push_back(4);
	for (std::vector<int>::iterator it = pouet.begin(); it != pouet.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "TEST" << std::endl;
	std::vector<int> soluce = test.twoSum(pouet, 6);
	for (std::vector<int>::iterator it = soluce.begin(); it != soluce.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "Sum = " << pouet[soluce[0]] + pouet[soluce[1]] << std::endl;
	return (0);
}
