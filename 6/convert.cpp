#include <iostream>

class Solution {
	public:
		std::string convert(std::string s, int numRows) {
			std::string	ret(s.size(), 0);
			int	firstGap;
			int	secondGap;
			bool	switchGap;
			std::string::iterator	pos;
			std::string::iterator	itRet = ret.begin();

			if (numRows < 2)
				return (s);

			firstGap = (numRows - 1) * 2;
			secondGap = 0;

			for (int row = 0; row < numRows; ++row)
			{
				switchGap = true;	
				pos = s.begin() + row;

				while(1)
				{
					if (pos < s.end())
						*itRet++ = *pos;
					else
						break;

					if (firstGap != 0 && (switchGap || secondGap == 0))
						pos += firstGap;
					else
						pos += secondGap;
					switchGap = !switchGap;
				}
				firstGap -= 2;
				secondGap += 2;
			};
			s = ret;
			return (s);
		}
};

int	main(int ac, char** av)
{
	if (ac < 3)
		return (1);
	Solution soluce;
	std::string s(av[1]);

	std::cout << soluce.convert(s, atoi(av[2])) << std::endl;
	return (0);
}
