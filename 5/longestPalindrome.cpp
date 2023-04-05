#include <iostream>

class Solution
{
	public:
		std::string longestPalindrome(std::string s)
		{
			if (s.size() == 0)
				return(s);

			std::string	ret(s.begin(), s.begin() + 1);
			std::string::iterator	it;
			std::string::iterator	begin;
			std::string::iterator	end;

			for (it = s.begin(); it + 1 != s.end(); ++it)
			{
				if (*it != *(it + 1) && (it != s.begin() && (*(it - 1) != *(it + 1))))
					continue;

				begin = it;
				end = it;
				
				while (*begin == *(end + 1))
					++end;
				while (begin != s.begin() && end + 1 != s.end() && *(begin - 1) == *(end + 1))
				{
					--begin;
					++end;
				}
				if (ret.size() <= static_cast<size_t>(end - begin + 1))
					ret.assign(begin, end + 1);
			}
			return (ret);
		}
};

int	main(int ac, char** av)
{
	if (ac < 2)
		return (1);

	Solution soluce;
	std::cout << soluce.longestPalindrome(av[1]) << " is the longest palindrome" << std::endl;

	return(0);
}
