#include <iostream>

class Solution
{
	public:
		std::string longestPalindrome(std::string s)
		{
			std::string	ret;
			std::string::iterator	it;
			std::string::iterator	begin;
			std::string::iterator	end;

			if (s.size() == 0)
				return(s);
			ret.assign(s.begin(), s.begin() + 1);

			for (it = s.begin(); it + 1 != s.end(); ++it)
			{
				if (*it != *(it + 1) && *(it - 1) != *(it + 1))
					continue;
				if (*(it - 1) == *(it + 1))
				{
					begin = it - 1;
					end = it + 1;
				}
				else if (*it == *(it + 1))
				{
					begin = it;
					end = it + 1;;
				}
				while (begin != s.begin() && end != s.end() && *(begin - 1) == *(end + 1))
				{
					--begin;
					++end;
				}
				if (ret.size() <= static_cast<size_t>(end - begin))
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
