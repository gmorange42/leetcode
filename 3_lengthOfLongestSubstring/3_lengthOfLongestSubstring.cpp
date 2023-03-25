#include <iostream>
#include <unordered_map>
#include <utility>

class	Solution
{
	public:
		int	lengthOfLongestSubstring(char* s)
		{
			int	length = 0;
			int	max = 0;
			std::unordered_map<char, int>	save;
			save.reserve(128);

			for (int i = 0; s[i]; ++i)
			{
				if (save.count(s[i]) == 0)
				{
					std::pair<char, int>	temp (s[i], i);
					save.insert(temp);
					++length;
				}
				else
				{
					if (max < length)
						max = length;
					length = 0;
					i = save[s[i]];
					save.clear();
				}
			}

			if (length > max)
				return (length);

			return	(max);
		}
};

int	main(int ac, char** av)
{
	Solution	soluce;
	if (ac == 1)
		return (0);
	std::cout << "The length of " << av[1] << " is " << soluce.lengthOfLongestSubstring(av[1]);
	return (0);
}
