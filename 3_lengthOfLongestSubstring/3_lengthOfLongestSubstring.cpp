#include <iostream>
#include <unordered_map>
#include <utility>

class	Solution
{
	public:
		int	lengthOfLongestSubstring(std::string s)
		{
			int	length = 0;
			int	max = 0;
			std::unordered_map<char, std::string::iterator>	save;
			save.reserve(128);

			for (std::string::iterator it = s.begin(); it != s.end(); ++it)
			{
				if (save.count(*it) == 0)
				{
					std::pair<char, std::string::iterator>	temp (*it, it);
					save.insert(temp);
					++length;
				}
				else
				{
					if (max < length)
						max = length;
					length = 0;
					it = save[*it];
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
